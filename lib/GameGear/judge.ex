alias SFML.Graphics.{Sprite}

defmodule GameGear.Judge do
  @moduledoc """
  描画オブジェクトが移動可能な範囲をジャッジする関数群
  """

  @eps 1.0e-10

  @doc """
  [xmin,ymin,xmax,ymax]の矩形範囲をはみ出た場合は、オブジェクトに反転を指示する
  """
  def overrun?(%{sprite: s, velocity: [vx, vy]}, [xmin, ymin, xmax, ymax]) do
    with(
      [x, y, w, h] = Sprite.get_global_bounds(s),
      x = x - xmin, xmax = xmax - w,
      y = y - ymin, ymax = ymax - h,
    do:
      [
        cond do
          abs(vx) < @eps -> 0
          x < 0    -> Float.ceil(100.0*x / vx)
          x > xmax -> Float.ceil(100.0*(x - xmax) / vx)
          true    -> 0
        end,
        cond do
          abs(vy) < @eps -> 0
          y < 0    -> Float.ceil(100.0*y / vy)
          y > ymax -> Float.ceil(100.0*(y - ymax) / vy)
          true    -> 0
        end
      ]
    )
    |> case do
        # {はみ出したサイド, はみ出した量(速度に対する比率)}
        [0, 0] -> {:inside, :xy, 0.0}
        [a, b] when a > b ->
          {if(a < 100, do: :cross, else: :outside), :x, a/100.0}
        [a, b] when a < b ->
          {if(b < 100, do: :cross, else: :outside), :y, b/100.0}
        [a, _] ->
          {if(a < 100, do: :cross, else: :outside), :corner, a/100.0}
    end
  end
end
