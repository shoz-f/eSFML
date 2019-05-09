alias SFML.Graphics.{Sprite, CircleShape, Vertex, VertexDeque, RenderWindow}
alias SFML.System.{Clock,Vector2}
alias GameGear.{Stage,Bullet,NWayDann,MintDann,Judge,TextureBox,JukeBox,TurtleGeo}
alias Gravite.{Body}


defmodule Actor do
  @moduledoc """
  描画オブジェクト
  """
  defstruct body: nil, speed: 1.0, velocity: [1.0, 0.0], alive: false, color: nil

  @actor __MODULE__

  def init() do
    TextureBox.create(name: @actor)
    Enum.each([
      penguin: "image/penguin.png",
      elixir:  "image/elixir.png",
      galaxy:  "image/galaxy.jpg"
    ], &TextureBox.add_from_file(&1, @actor))
  end

  @doc """
  オブジェクトを作成する
  """
  def create([_x, _y] = pos, speed, dir, img) do
    dir = :math.fmod(dir, 360.0)
    left_pointing? = (dir > 90.0 && dir < 270.0)
    %Actor{
      body:   TextureBox.get(img, @actor)
                |> Sprite.create()
                |> Sprite.set_origin(:center)
                |> Sprite.set_position(pos)
                |> Sprite.set_rotation(dir)
                |> (&if left_pointing? do Sprite.flip(&1) else &1 end).(),
      speed:    speed,
      velocity: [speed*:math.cos(:math.pi*dir/180.0),
                 speed*:math.sin(:math.pi*dir/180.0)],
      alive:    true
    }
  end

  @doc """
  オブジェクトを複製する
  """
  def clone(org, opt) do
    with color = opt[:color],
      [cvx,_] = v = opt[:velocity] || org.velocity,
      [ovx,_] = org.velocity,
      flip?   = ovx*cvx < 0.0
    do
      %Actor{
        body:   Sprite.clone(org.body)
                  |> (&if flip? do Sprite.flip(&1) else &1 end).()
                  |> (&if color do Sprite.set_color(&1, color) else &1 end).(),
        velocity: v
      }
    end
  end
  
  @doc """
  """
  def scale(%Actor{body: s} = a, factor) do
    Sprite.scale(s, factor)
    a
  end
  
  @doc """
  テクスチャと左右の動きを反転させる。
  """
  def flip(%Actor{body: s, velocity: [x, y]} = p) do
    Sprite.flip(s)
    %Actor{p | velocity: [-x, y]}
  end

  @doc """
  上下の動きを反転させる
  """
  def flop(%Actor{velocity: [x, y]} = p) do
    %Actor{p | velocity: [x, -y]}
  end
  
  @doc """
  オブジェクトの状態・動きを更新する
  """
  def update(%Actor{} = actor, time, overrun?) do
    TurtleGeo.forward(actor)
    case overrun?.(actor) do
      {:inside, _, _} -> actor
      {_, :x, step} ->
        TurtleGeo.backward(actor, step) |> flip
      {_, :y, step} ->
        TurtleGeo.backward(actor, step) |> flop
      {_, :corner, step} ->
        TurtleGeo.backward(actor, step) |> flip |> flop
    end
  end
end


defmodule Comet do
  @moduledoc """
  描画オブジェクト
  """
  defstruct body: nil, speed: 1.0, velocity: [1.0, 0.0], alive: false, color: nil

  @doc """
  オブジェクトを作成する
  """
  def create([_x, _y] = pos, speed, dir) do
    dir = :math.fmod(dir, 360.0)
    left_pointing? = (dir > 90.0 && dir < 270.0)
    %Comet{
      body:   CircleShape.create()
                |> CircleShape.set_radius(2.0)
                |> CircleShape.set_position(pos),
      speed:    speed,
      velocity: [speed*:math.cos(:math.pi*dir/180.0),
                 speed*:math.sin(:math.pi*dir/180.0)],
      alive:    true
    }
  end

  @doc """
  左右の動きを反転させる。
  """
  def flip(%Comet{velocity: [x, y]} = p) do
    %Comet{p | velocity: [-x, y]}
  end

  @doc """
  上下の動きを反転させる
  """
  def flop(%Comet{velocity: [x, y]} = p) do
    %Comet{p | velocity: [x, -y]}
  end
  

  @doc """
  オブジェクトの状態・動きを更新する
  """
  def update(%Comet{body: s, velocity: [vx,vy]} = comet, time, overrun?) do
    CircleShape.move(s, [vx,vy])
    case overrun?.(comet) do
      {:inside, _, _} -> comet
      {_, :x, step} ->
        CircleShape.move(s, [-vx, -vy])
        comet |> flip
      {_, :y, step} ->
        CircleShape.move(s, [-vx, -vy])
        comet |> flop
      {_, :corner, step} ->
        CircleShape.move(s, [-vx, -vy])
        comet |> flip |> flop
    end
  end
end

defmodule FlyingElixir do
  def run() do
    Actor.init()
    stage  = Stage.create([800, 600], "Flying Elixir!", [200,200,200])
    actor  = Actor.create([150.0, 168.0], 2.0, 0.0, :elixir)
    actors = Enum.map([
      {[ 3.0, 1.8], :Cyan   },
      {[ 1.5, 0.3], :Red    },
      {[ 2.0,-0.8], :Green  },
      {[ 2.3,-2.2], :Blue   },
      {[-2.0, 1.5], :Yellow },
      {[-2.7, 1.0], :Magenta},
      {[-1.0,-0.4], :White  },
      {[-1.5,-1.4], [255,0,0,100]},
    ], fn {v, c} -> Actor.clone(actor, velocity: v, color: c) end)

    overrun? = &Judge.overrun?(&1, Stage.border(stage))

    until_loop = fn
      (true, _, _) ->
        :ok
      (false, actors, loop)  ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &Actor.update(&1, 2, overrun?))

        loop.(Stage.keypressed?(stage, 36), actors, loop)
    end
    until_loop.(false, actors, until_loop)
 
    Stage.discard(stage)
    :ok
  end
end

defmodule WalkingPenguin do
  def run() do
    Actor.init()
    stage = Stage.create([800, 600], "Walking Penguin!", [200,150,150])
    actor = Actor.create([400.0, 300.0], 2.0, 5.0, :penguin)

    overrun? = &Judge.overrun?(&1, Stage.border(stage))

    until_loop = fn
      (true, _, _) ->
        :ok
      (false, actors, loop)  ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &Actor.update(&1, 2, overrun?))

        loop.(Stage.keypressed?(stage, 36), actors, loop)
    end
    until_loop.(false, [actor], until_loop)

    Stage.discard(stage)
    :ok
  end
end

defmodule FlyingComet do
  def run() do
    stage = Stage.create([800, 600], "Flying Comet!", [200,150,150])
    comet = Comet.create([400.0, 300.0], 2.0, 5.0)

    overrun? = &Judge.overrun2?(&1, Stage.border(stage))

    until_loop = fn
      (true, _, _) ->
        :ok
      (false, comets, loop)  ->
        Stage.update(stage, comets)
        comets = Enum.map(comets, &Comet.update(&1, 2, overrun?))

        loop.(Stage.keypressed?(stage, 36), comets, loop)
    end
    until_loop.(false, [comet], until_loop)

    Stage.discard(stage)
    :ok
  end
end

defmodule Galaxy do
  def load_bgm() do
    JukeBox.create()
    JukeBox.add_from_file({:jupiter, "sound/jupiter.wav"})
  end

  def run() do
    Actor.init()
    stage = Stage.create([600,600], "Galaxy!", :Black)
    actor = Actor.create([400.0, 400.0], 0.0, 0.0, :galaxy)
              |> Actor.scale([2.0, 2.0])

#    load_bgm()
#    JukeBox.play(:jupiter)

    until_loop = fn
      (true, _, _) ->
        :ok
      (false, actors, loop) ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &TurtleGeo.right(&1, 0.2))
        loop.(Stage.keypressed?(stage, 36), actors, loop)
    end
    until_loop.(false, [actor], until_loop)
    
#    JukeBox.stop(:jupiter)
    Stage.discard(stage)
    :ok
  end
end

defmodule TestBullet do
  def run() do
    Bullet.init()
    stage  = Stage.create([600,600], "N-Way Dann!", :Black)
    launch = NWayDann.create()

    overrun? = &Judge.overrun?(&1, Stage.border(stage))
    
    until_loop = fn
      (true, _, _, _) ->
        :ok
      (false, [x,y], bullets, loop) ->
        Stage.update(stage, bullets)
        bullets = Enum.map(bullets, &Bullet.update(&1, overrun?))
                  |> Enum.filter(&Bullet.is_alive?(&1))
        bullets = NWayDann.shot(launch, [x,y]) ++ bullets

        event = Stage.poll_event(stage)
        x = case event do
          {:keypressed, 79} -> x-5
          {:keypressed, 81} -> x+5
          _ -> x
        end

        loop.(event == {:keypressed, 36}, [x,y], bullets, loop)
    end
    until_loop.(false, [300.0, 300.0], [], until_loop)
    
    NWayDann.discard(launch)
    Stage.discard(stage)
    :ok
  end
end

defmodule TestMint do
  def run() do
    Bullet.init()
    stage  = Stage.create([600,600], "Linux Mint!", :Black)
    launch = MintDann.create()

    overrun? = &Judge.overrun?(&1, Stage.border(stage))
    
    until_loop = fn
      (true, _, _, _) ->
        :ok
      (false, [x,y], bullets, loop) ->
        Stage.update(stage, bullets)
        bullets = Enum.map(bullets, &Bullet.update(&1, overrun?))
                  |> Enum.filter(&Bullet.is_alive?(&1))
        bullets = MintDann.shot(launch, [x,y]) ++ bullets

        event = Stage.poll_event(stage)
        x = case event do
          {:keypressed, 79} -> x-5
          {:keypressed, 81} -> x+5
          _ -> x
        end

        loop.(event == {:keypressed, 36}, [x,y], bullets, loop)
    end
    until_loop.(false, [300.0, 300.0], [], until_loop)
    
    MintDann.discard(launch)
    Stage.discard(stage)
    :ok
  end
end


defmodule TestVertices do
  def run() do
    triangle = [
      %Vertex{position: [ 10.0,  10.0], color: :Red  },
      %Vertex{position: [100.0,  10.0], color: :Blue },
      %Vertex{position: [100.0, 100.0], color: :Green}
    ]

    win = RenderWindow.create([480,320], "Vertices")
    
    RenderWindow.clear(win, :Black)
    RenderWindow.drawvertex(win, triangle, :Triangles)
    RenderWindow.display(win)
  end
end

defmodule TestVertexDeque do
  def run() do
    vd = VertexDeque.create(5)
           |> VertexDeque.set_primitive_type(:LineStrip)
           |> VertexDeque.push([10,20])
           |> VertexDeque.push([50,80])
           |> VertexDeque.push([40,100])

    win = RenderWindow.create([480,320], "VertexDeque")
    
    RenderWindow.clear(win, :Black)
    RenderWindow.draw(win, vd)
    RenderWindow.display(win)
    
  end
end

defmodule Orbit do
  def run() do
  end
end
