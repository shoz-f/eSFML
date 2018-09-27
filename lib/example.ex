alias SFML.Graphics.{RenderWindow,Sprite,Texture}
alias SFML.System.{Clock,Vector2}

defmodule Penguin do
  @moduledoc """
  描画オブジェクト:ペンギン
  """
  defstruct sprite: nil, velocity: [0.0, 0.0]
  
  @doc """
  オブジェクトを作成する
  """
  def create(t, pos, [vx,_] = v) do
    %Penguin{
      sprite:   Sprite.create(t)
                |> Sprite.set_position(pos)
                |> (&if vx < 0 do Sprite.flip(&1) else &1 end).(),
      velocity: v
    }
  end

  @doc """
  オブジェクトをvelocityの方向に移動させる
  """
  def walk(%Penguin{sprite: s, velocity: v} = p, time) do
    Sprite.move(s, Vector2.scale(v, time))
    p
  end

  @doc """
  オブジェクトをstepだけ後戻りさせる
  """
  def goback(%Penguin{sprite: s, velocity: v} = p, step) do
    Sprite.move(s, Vector2.scale(v, -step))
    p
  end

  @doc """
  テクスチャと左右の動きを反転させる。
  """
  def flip(%Penguin{sprite: s, velocity: [x, y]} = p) do
    Sprite.flip(s)
    %Penguin{p | velocity: [-x, y]}
  end

  @doc """
  上下の動きを反転させる
  """
  def flop(%Penguin{velocity: [x, y]} = p) do
    %Penguin{p | velocity: [x, -y]}
  end
  
  @doc """
  オブジェクトの状態・動きを更新する
  """
  def update(%Penguin{} = p, time, overrun?) do
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
  def create([width, height], title, color) do
    %Stage{
      win: RenderWindow.create(width, height, title),
      bg:  color
    }
  end

  @doc """
  ステージを破棄
  """
  def destroy(%Stage{win: w}) do
    RenderWindow.destroy(w)
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
    do: [
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
  defstruct clock: nil, texture: nil, stage: nil, pen: nil

  @doc """
  
  """
  def run() do
    app = %Main {
            clock:   Clock.create(),
            texture: %{ penguin: Texture.load_from_file('image/penguin.png') },
          }

    s = Stage.create([600, 600], 'Penguin walk!', :Cyan)

    p = [Penguin.create(app.texture[:penguin], [0.0, 168.0], [2.0, -0.4])]

    overrun? = &Judge.overrun?(&1, Stage.border(s))
    
    loop(400, s, p, overrun?)
  end
 
  @doc """
  メイン・ループ
  """
  defp loop(0, _s, _p, _overrun?) do
  end

  defp loop(n, s, p, overrun?) do
    Stage.update(s, p)
    Process.sleep(1)
    p = Enum.map(p, &Penguin.update(&1, 2, overrun?))
    loop(n-1, s, p, overrun?)
  end
end
