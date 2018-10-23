alias SFML.Graphics.{Sprite}
alias SFML.System.{Clock,Vector2}
alias GameGear.{Stage,Bullet,NWayDann,Judge,TextureBox,JukeBox}


defmodule Actor do
  @moduledoc """
  描画オブジェクト
  """
  defstruct sprite: nil, speed: 1.0, velocity: [0.0, 0.0], alive: false, color: nil

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
  def create([_x, _y] = pos, [vx,_] = v, img) do
    %Actor{
      sprite:   TextureBox.get(img, @actor)
                |> Sprite.create()
                |> Sprite.set_origin(:center)
                |> Sprite.set_position(pos)
                |> (&if vx < 0 do Sprite.flip(&1) else &1 end).(),
      velocity: v,
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
        sprite:   Sprite.clone(org.sprite)
                  |> (&if flip? do Sprite.flip(&1) else &1 end).()
                  |> (&if color do Sprite.set_color(&1, color) else &1 end).(),
        velocity: v
      }
    end
  end
  
  @doc """
  """
  def set_origin(%Actor{sprite: s} = a, org) do
    Sprite.set_origin(s, org)
    a
  end
  
  @doc """
  """
  def scale(%Actor{sprite: s} = a, factor) do
    Sprite.scale(s, factor)
    a
  end
  
  @doc """
  """
  def rotate(%Actor{sprite: s} = a, angle) do
    Sprite.rotate(s, angle)
    a
  end
  
  @doc """
  オブジェクトの速度をvに変更する
  """
  def set_velocity(%Actor{} = p, [vx,_] = v) do
    if vx < 0 do Sprite.flip(p.sprite) end
    %Actor{p | velocity: v}
  end

  @doc """
  オブジェクトをvelocityの方向に移動させる
  """
  def walk(%Actor{sprite: s, velocity: v} = a, time) do
    Sprite.move(s, Vector2.scale(v, time))
    a
  end

  @doc """
  オブジェクトをstepだけ後戻りさせる
  """
  def goback(%Actor{sprite: s, velocity: v} = p, step) do
    Sprite.move(s, Vector2.scale(v, -step))
    p
  end

  @doc """
  テクスチャと左右の動きを反転させる。
  """
  def flip(%Actor{sprite: s, velocity: [x, y]} = p) do
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
  def update(%Actor{} = p, time, overrun?) do
    walk(p, time)
    case overrun?.(p) do
      {:inside, _, _} -> p
      {_, :x, step} ->
        goback(p, step) |> flip
      {_, :y, step} ->
        goback(p, step) |> flop
      {_, :corner, step} ->
        goback(p, step) |> flip |> flop
    end
  end
end






defmodule Main do
  @moduledoc """
  メイン・ルーチン群
  """

  def load_bgm() do
    JukeBox.create()
    JukeBox.add_from_file({:jupiter, "sound/jupiter.wav"})
  end

  def test_bullet() do
    Bullet.init()
    stage = Stage.create([600,600], "N-Way Dann!", :Black)
    bullets = for angle <- 0..17 do
      Bullet.shot([300.0, 300.0], 2.0, 20.0*angle, :b1)
    end

    overrun? = &Judge.overrun?(&1, Stage.border(stage))
    
    pid = NWayDann.create()
    main_loop(Stage.keypressed?(stage, 36),stage,[],overrun?,pid)
    
    Stage.destroy(stage)
  end

  def main_loop(true,_,_,_,_) do
    :ok
  end
  def main_loop(false,stage,actors,overrun?,pid) do
    Stage.update(stage, actors)
    actors = Enum.map(actors, &Bullet.update(&1, overrun?))
             |> Enum.filter(&Bullet.is_alive?(&1))
    actors = NWayDann.shot(pid) ++ actors
    main_loop(Stage.keypressed?(stage, 36), stage, actors, overrun?, pid)
  end


  def flying_elixir() do
    Actor.init()
    stage = Stage.create([800, 600], "Flying Elixir!", [200,200,200])
    actor = Actor.create([150.0, 168.0], [1.0, 0.0], :elixir)
    run(stage,
      Enum.map([
        {[ 3.0, 1.8], :Cyan   },
        {[ 1.5, 0.3], :Red    },
        {[ 2.0,-0.8], :Green  },
        {[ 2.3,-2.2], :Blue   },
        {[-2.0, 1.5], :Yellow },
        {[-2.7, 1.0], :Magenta},
        {[-1.0,-0.4], :White  },
        {[-1.5,-1.4], [255,0,0,100]},
      ], fn {v, c} -> Actor.clone(actor, velocity: v, color: c) end)
    )
    Stage.destroy(stage)
  end
  
  def walking_penguin() do
    Actor.init()
    stage = Stage.create([800, 600], "Walking Penguin!", [200,150,150])
    actor = Actor.create([400.0, 300.0], [1.0, 0.3], :penguin)
    run(stage, [actor])
    Stage.destroy(stage)
  end

  def galaxy() do
    Actor.init()
    load_bgm()
    stage = Stage.create([600,600], "Galaxy!", :Black)
    actor = Actor.create([400.0, 400.0], [1.0, 0.0], :galaxy)
              |> Actor.set_origin([320.0, 230.0])
              |> Actor.scale([2.0, 2.0])
    
#    JukeBox.play(:jupiter)
 
    until = fn
      (true, _, _) ->
        :ok
      (false, actors, cont) ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &Actor.rotate(&1, 0.2))
        cont.(Stage.keypressed?(stage, 36), actors, cont)
    end
    until.(false, [actor], until)
    
#    JukeBox.stop(:jupiter)
    Stage.destroy(stage)
  end
 
  def run(stage, actors) do
    overrun? = &Judge.overrun?(&1, Stage.border(stage))
    
    until = fn
      (true, _, _) ->
        :ok
      (false, actors, cont)  ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &Actor.update(&1, 2, overrun?))
        cont.(Stage.keypressed?(stage, 36), actors, cont)
    end
    until.(false, actors, until)
  end
end