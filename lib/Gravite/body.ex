defmodule Gravite.Body do
  defstruct [
    pos:       [0.0, 0.0],
    prev_pos:  [0.0, 0.0],
    angle:     0.0,
    velocity:  [0.0, 0.0],
    anguler_v: 0.0,
    force:     [0.0, 0.0],
    torque:    0.0,
    mass:      1.0,
    inertia:   1.0,
    friction:  [0.0, 0.0],
    shape:     nil
  ]

  def euler(%{pos: [x0, y0], force: [fx, fy], mass: m}, tick) do
  end
  
  def verlet(%{pos: [x1, y1], prev_pos: [x0, y0], force: [fx, fy], mass: m}, tick) do
    [2*x1 - x0 + fx/m*:math.pow(tick,2), 2*y1 - y0 + fy/m*:math.pow(tick,2)]
  end
  
  
  def verlet(x0, v0, f0, f1, m, tick) do
    x0 + tick*v0 + 1/2*:math.pow(tick,2)*f0/m
    v0 + 1/2*tick*(f0+f1)/m
  end
end
