defmodule SFML.Graphics.Sprite do
  alias SFML.Graphics.NIF

  defdelegate create(texture),           to: NIF, as: :sprite_create
  defdelegate set_texture(s, texture),   to: NIF, as: :sprite_set_texture
  defdelegate set_texture_rect(s, rect), to: NIF, as: :sprite_set_texture_rect
  defdelegate get_position(s),           to: NIF, as: :sprite_get_position
  defdelegate set_position(s, pos),      to: NIF, as: :sprite_set_position
  defdelegate get_rotation(s),           to: NIF, as: :sprite_get_rotation
  defdelegate set_rotation(s, angle),    to: NIF, as: :sprite_set_rotation
  defdelegate get_scale(s),              to: NIF, as: :sprite_get_scale
  defdelegate set_scale(s, factors),     to: NIF, as: :sprite_set_scale
  defdelegate move(s, delta),            to: NIF, as: :sprite_move
  defdelegate rotate(s, angle),          to: NIF, as: :sprite_rotate
  defdelegate scale(s, factor),          to: NIF, as: :sprite_scale
  defdelegate flip(s),                   to: NIF, as: :sprite_flip
  defdelegate get_global_bounds(s),      to: NIF, as: :sprite_get_global_bounds
end
