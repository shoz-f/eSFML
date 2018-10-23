alias SFML.Graphics.{Sprite}
alias GameGear.{TextureBox,TurtleGeo}

alias GameGear.Bullet

defmodule GameGear.Bullet do
  defstruct sprite: nil, speed: 1.0, velocity: [1.0, 0.0], alive: false

  @bullet __MODULE__

  def init() do
    TextureBox.create(name: @bullet)
    Enum.each([
      b1: "image/b1.png",
      b2: "image/bb1.png"
    ], &TextureBox.add_from_file(&1, @bullet))
  end

  def is_alive?(%{alive: alive} = bullet) do
      if(alive, do: bullet, else: nil)
  end

  def shot([_x, _y] = pos, speed, dir, img) do
    %Bullet{
      sprite:   TextureBox.get(img, @bullet)
                |> Sprite.create()
                |> Sprite.set_origin(:center)
                |> Sprite.set_position(pos)
                |> Sprite.set_rotation(dir),
      speed:    speed,
      velocity: [speed*:math.cos(:math.pi*dir/180.0),
                 speed*:math.sin(:math.pi*dir/180.0)],
      alive:    true
    }
  end
  
  def update(%Bullet{}=bullet, overrun?) do
    TurtleGeo.forward(bullet)
    case overrun?.(bullet) do
      {:outside, _, _} -> %{bullet| alive: false}
      {_, _, _}        -> bullet
    end
  end
end
