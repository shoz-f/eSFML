defmodule GameGear.Turtle do
  defstruct pos: [0.0, 0.0], theta: 0, speed: 1.0
  
  def forward(kame, step) do
    with %{pos: [x,y], theta: theta, speed: speed} = kame,
      dx = step*speed*deg_cos(theta),
      dy = step*speed*deg_sin(theta)
    do
      %{kame | pos: [x+dx, y+dy]}
    end
  end
  
  def left(kame, angle) do
    with theta = kame.theta
    do
      %{kame | theta: deg_norm(theta + angle)}
    end
  end

  def right(kame, angle) do
    with theta = kame.theta
    do
      %{kame | theta: deg_norm(theta - angle)}
    end
  end

  defp deg_cos(degree) do
    :math.cos(:math.pi*degree/180.0)
  end

  defp deg_sin(degree) do
    :math.sin(:math.pi*degree/180.0)
  end

  defp deg_norm(degree) do
    Integer.mod(degree, 360)
  end
end
