defmodule SFML.Graphics.Sprite do
  alias SFML.Graphics.NIF

  defstruct [:obj]

  def set_origin(s, :center) do
    [x1, y1, x2, y2] = get_texture_rect(s)
    set_origin(s, [(x1+x2)/2.0, (y1+y2)/2.0])
  end

  defdelegate create(texture),           to: NIF, as: :sprite_create
  defdelegate clone(texture),            to: NIF, as: :sprite_clone
  defdelegate set_texture(s, texture),   to: NIF, as: :sprite_set_texture
  defdelegate set_texture_rect(s, rect), to: NIF, as: :sprite_set_texture_rect
  defdelegate get_texture_rect(s),       to: NIF, as: :sprite_get_texture_rect
  defdelegate get_origin(s),             to: NIF, as: :sprite_get_origin
  defdelegate set_origin(s, org),        to: NIF, as: :sprite_set_origin
  defdelegate get_position(s),           to: NIF, as: :sprite_get_position
  defdelegate set_position(s, pos),      to: NIF, as: :sprite_set_position
  defdelegate get_rotation(s),           to: NIF, as: :sprite_get_rotation
  defdelegate set_rotation(s, angle),    to: NIF, as: :sprite_set_rotation
  defdelegate get_scale(s),              to: NIF, as: :sprite_get_scale
  defdelegate set_scale(s, factors),     to: NIF, as: :sprite_set_scale
  defdelegate get_color(s),              to: NIF, as: :sprite_get_color
  defdelegate set_color(s, color),       to: NIF, as: :sprite_set_color
  defdelegate move(s, delta),            to: NIF, as: :sprite_move
  defdelegate rotate(s, angle),          to: NIF, as: :sprite_rotate
  defdelegate scale(s, factor),          to: NIF, as: :sprite_scale
  defdelegate flip(s),                   to: NIF, as: :sprite_flip
  defdelegate get_global_bounds(s),      to: NIF, as: :sprite_get_global_bounds
end
