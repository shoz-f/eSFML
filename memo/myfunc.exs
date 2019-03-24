defmodule MyFunc do
  def rand_loc(max_x, max_y) do
    [ :rand.uniform(max_x), :rand.uniform(max_y) ]
  end
  
  def rand_loc(max_x, max_y, n) do
    Stream.repeatedly(fn -> rand_loc(max_x, max_y) end)
    |> Enum.take(n)
  end
  
  def within([x, y], [min_x, min_y], [max_x, max_y]) do
    (min_x <= x && x <= max_x) && (min_y <= y && y <= max_y)
  end
  
  def group_within(list, min_p, max_p) do
    Enum.group_by(list, &within(&1, min_p, max_p))
  end
end

defmodule Enemy do
  defstruct loc: [0,0], size: [10, 10], texture: nil
end
