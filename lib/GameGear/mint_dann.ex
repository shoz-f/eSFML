alias GameGear.{Bullet}

alias GameGear.MintDann

defmodule GameGear.MintDann do
  defstruct interval: 1, dir: 90.0, rot: 10.0

  def create() do
    {:ok, pid} = Agent.start_link(fn -> %MintDann{} end)
    pid
  end
  
  def discard(pid) do
    Agent.stop(pid)
  end

  def nway(way, pitch, direction \\ [0.0]) do
    org = -pitch*(way-1) / 2
    for dir <- direction, j <- 0..(way-1) do
      org + dir + pitch*j
    end
  end

  def shot(pid, [_x,_y]=pos) do
    case Agent.get(pid, &(&1)) do
    %{interval: count = 50, dir: dir, rot: rot} ->
      Agent.update(pid, &(%{&1| interval: 1, dir: dir+rot}))
      for delta <- nway(1, 8.0, [0.0, 60.0, 120.0, 180.0, 250.0, 310.0]) do
        Bullet.shot(pos, 1.0, dir+delta, :b3)
      end
#    %{interval: count = 50, dir: dir, rot: rot} ->
#      Agent.update(pid, &(%{&1| interval: 1, dir: dir+rot}))
#      for delta <- nway(5, 8.0, [0.0, 180.0]) do
#        Bullet.shot(pos, 2.0, dir+delta, :b3)
#      end
    %{interval: count} ->
      Agent.update(pid, &(%{&1| interval: count+1}))
      []
    end
  end
end
