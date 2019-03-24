alias SFML.Graphics.{Sprite}
alias SFML.System.{Vector2}

defmodule GameGear.TurtleGeo do
  def forward(%{body: s, velocity: [vx, vy]}=kame) do
    Sprite.move(s, [vx, vy])
    kame
  end

  def forward(%{body: s, velocity: v}=kame, step) do
    Sprite.move(s, Vector2.scale(v, step))
    kame
  end

  def backward(%{body: s, velocity: [vx, vy]}=kame) do
    Sprite.move(s, [-vx, -vy])
    kame
  end

  def backward(%{body: s, velocity: v}=kame, step) do
    Sprite.move(s, Vector2.scale(v, -step))
    kame
  end

  def right(%{body: s, speed: speed}=kame, angle) do
    Sprite.rotate(s, angle)
    dir = Sprite.get_rotation(s)
    %{kame| velocity: [speed*:math.cos(:math.pi*dir/180.0),
                       speed*:math.sin(:math.pi*dir/180.0)]}
  end

  def left(kame, angle) do
    right(kame, -angle)
  end

  def right_pointing?(%{body: s}) do
    dir = :math.fmod(Sprite.get_rotation(s), 360.0)
    dir < 90.0 || dir > 270.0
  end
  
  def left_pointing?(%{body: _s}=kame) do
    !right_pointing?(kame)
  end
end
