alias GameGear.{Bullet}

alias GameGear.NWayDann

defmodule GameGear.NWayDann do
  defstruct interval: 1, dir: 90.0, rot: 10.0

  def create() do
    {:ok, pid} = Agent.start_link(fn -> %NWayDann{} end)
    pid
  end
  
  def nway(way, pitch, direction \\ [0.0]) do
    org = -pitch*(way-1) / 2
    for dir <- direction, j <- 0..(way-1) do
      org + dir + pitch*j
    end
  end

  def shot(id) do
    case Agent.get(id, &(&1)) do
    %{interval: count = 25, dir: dir, rot: rot} ->
      Agent.update(id, &(%{&1| interval: count+1, dir: dir+rot}))
      for delta <- nway(3, 8.0, [0.0, 120.0, 180.0, 300.0]) do
        Bullet.shot([300.0, 300.0], 2.0, dir+delta, :b1)
      end
    %{interval: count = 50, dir: dir, rot: rot} ->
      Agent.update(id, &(%{&1| interval: 1, dir: dir+rot}))
      for delta <- nway(5, 8.0, [0.0, 180.0]) do
        Bullet.shot([300.0, 300.0], 2.0, dir+delta, :b2)
      end
    %{interval: count} ->
      Agent.update(id, &(%{&1| interval: count+1}))
      []
    end
  end
end
