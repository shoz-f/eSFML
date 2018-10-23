alias SFML.Graphics.{Sprite}

defmodule GameGear.TurtleGeo do
  def forward(%{sprite: s, velocity: [vx, vy]}=kame) do
    Sprite.move(s, [vx, vy])
    kame
  end

  def right(%{sprite: s, speed: speed}=kame, angle) do
    Sprite.rotate(s, angle)
    dir = Sprite.get_rotation(s)
    %{kame| velocity: [speed*:math.cos(:math.pi*dir/180.0),
                       speed*:math.sin(:math.pi*dir/180.0)]}
  end

  def left(%{sprite: _s, speed: _speed}=kame, angle) do
    right(kame, -angle)
  end
end
