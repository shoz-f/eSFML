alias SFML.Graphics.{RenderWindow,Sprite,Texture}
alias SFML.System.{Clock,Vector2}

defmodule Actor do
  @moduledoc """
  描画オブジェクト
  """
  defstruct sprite: nil, velocity: [0.0, 0.0], color: nil
  
  @doc """
  オブジェクトを作成する
  """
  def create(t, pos, [vx,_] = v) do
    %Actor{
      sprite:   Sprite.create(t)
                |> Sprite.set_position(pos)
                |> (&if vx < 0 do Sprite.flip(&1) else &1 end).(),
      velocity: v
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
  オブジェクトの速度をvに変更する
  """
  def set_velocity(%Actor{} = p, [vx,_] = v) do
    if vx < 0 do Sprite.flip(p.sprite) end
    %Actor{p | velocity: v}
  end

  @doc """
  オブジェクトをvelocityの方向に移動させる
  """
  def walk(%Actor{sprite: s, velocity: v} = p, time) do
    Sprite.move(s, Vector2.scale(v, time))
    p
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
      {:inside, _} -> p
      {:outx, step} ->
        goback(p, step) |> flip
      {:outy, step} ->
        goback(p, step) |> flop
      {:corner, step} ->
        goback(p, step) |> flip |> flop
    end
  end
end



defmodule Stage do
  @moduledoc """
  描画オブジェクトを描画するステージ
  """
  defstruct win: nil, bg: :Black
  
  @doc """
  ステージを作成
  """
  def create([_width, _height] = size, title, color) do
    %Stage{
      win: RenderWindow.create(size, title),
#           |> RenderWindow.set_framerate_limit(60),
      bg:  color
    }
  end

  @doc """
  ステージを破棄
  """
  def destroy(%Stage{win: w}) do
    RenderWindow.destroy(w)
  end

  def keypressed?(%Stage{win: w}, val) do
    RenderWindow.poll_event(w) == {:keypressed, val}
  end

  @doc """
  ステージの中と外の境界を返す: [left,top,right,bottom]
  """
  def border(%Stage{win: w}) do
    [0.0, 0.0] ++ RenderWindow.get_size(w)
  end
  
  @doc """
  ステージを更新する
  """
  def update(%Stage{win: w, bg: color}, e_list) do
    RenderWindow.clear(w, color)
    Enum.each(e_list, &RenderWindow.draw(w, &1.sprite))
    RenderWindow.display(w)
  end
end



defmodule Judge do
  @moduledoc """
  描画オブジェクトが移動可能な範囲をジャッジする関数群
  """

  @doc """
  [xmin,ymin,xmax,ymax]の矩形範囲をはみ出た場合は、オブジェクトに反転を指示する
  """
  def overrun?(entity,[xmin,ymin,xmax,ymax]) do
    with(
      eps = 1.0e-10,
      [x,y,w,h] = Sprite.get_global_bounds(entity.sprite),
      [vx, vy]  = entity.velocity,
      x = x - xmin, xmax = xmax - w,
      y = y - ymin, ymax = ymax - h,
    do:
      [
        cond do
          abs(vx) < eps -> 0
          x < 0    -> Float.ceil(100.0*x / vx)
          x > xmax -> Float.ceil(100.0*(x - xmax) / vx)
          true    -> 0
        end,
        cond do
          abs(vy) < eps -> 0
          y < 0    -> Float.ceil(100.0*y / vy)
          y > ymax -> Float.ceil(100.0*(y - ymax) / vy)
          true    -> 0
        end
      ]
    )
    |> case do
        # {はみ出したサイド, はみ出した量(速度に対する比率)}
        [0, 0] -> {:inside, 0.0}
        [a, b] when a > b -> {:outx, a/100.0}
        [a, b] when a < b -> {:outy, b/100.0}
        [a, _] -> {:corner, a/100.0}
    end
  end
end



defmodule Main do
  @moduledoc """
  メイン・ルーチン群
  """
  defstruct clock: nil, texture: nil, stage: nil, pen: nil, entity: []

  @doc """
  
  """
  def load_texture() do
    %{
      penguin: Texture.load_from_file("image/penguin.png"),
      elixir:  Texture.load_from_file("image/elixir.png")
    }
  end

  def flying_elixir() do
    texture = load_texture()
    stage   = Stage.create([800, 600], "Flying Elixir!", [200,200,200])
    actor   = Actor.create(texture[:elixir], [150.0, 168.0], [1.0, 0.0])
    run(stage,
      Enum.map([
      [[ 3.0, 1.8], :Cyan   ],
      [[ 1.5, 0.3], :Red    ],
      [[ 2.0,-0.8], :Green  ],
      [[ 2.3,-2.2], :Blue   ],
      [[-2.0, 1.5], :Yellow ],
      [[-2.7, 1.0], :Magenta],
      [[-1.0,-0.4], :White  ],
      [[-1.5,-1.4], [255,0,0,100]],
      ], fn [v, c] -> Actor.clone(actor, velocity: v, color: c) end)
    )
  end
  
  def walking_penguin() do
    texture = load_texture()
    stage   = Stage.create([800, 600], "Walking Penguin!", [200,150,150])
    actor   = Actor.create(texture[:penguin], [400.0, 300.0], [1.0, 0.3])
    run(stage, [actor])
  end
  
  def run(stage, actors) do
    overrun? = &Judge.overrun?(&1, Stage.border(stage))
    
    until = fn
      (true, _, _) ->
        Stage.destroy(stage)
      (false, actors, cont)  ->
        Stage.update(stage, actors)
        actors = Enum.map(actors, &Actor.update(&1, 2, overrun?))
        cont.(Stage.keypressed?(stage, 36), actors, cont)
    end
    until.(false, actors, until)
  end
end
