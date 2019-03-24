defmodule Gravite.Particle do

  defstruct [
    mass:     1.0,
    pos:      [0.0, 0.0],
    velocity: [0.0, 0.0],
    force:    [0.0, 0.0],
  ]

#particles = [
#  %Particle{mass: 1.0},
#  %Particle{}
#]

  def combination(list) do
    combination_sub(Enum.reverse(list))
  end
  
  def combination_sub([]) do
    []
  end

  def combination_sub([head|tail]) do
    comb = Enum.map(tail, fn x -> [x, head] end)
    [comb|combination_sub(tail)]
  end

end
