defmodule SFML.Graphics.RectangleShape do
  alias SFML.Graphics.NIF

  defdelegate create(),                     to: NIF, as: :rectangle_shape_create
  defdelegate destroy(cs),                  to: NIF, as: :rectangle_shape_destroy
  defdelegate get_radius(cs),               to: NIF, as: :rectangle_shape_get_size
  defdelegate set_radius(cs,r),             to: NIF, as: :rectangle_shape_set_size
  defdelegate get_point(cs),                to: NIF, as: :rectangle_shape_get_point
  defdelegate get_outline_thickness(cs),    to: NIF, as: :rectangle_shape_get_outline_thickness
  defdelegate set_outline_thickness(cs,t),  to: NIF, as: :rectangle_shape_set_outline_thickness
  defdelegate set_texture(cs,t),            to: NIF, as: :rectangle_shape_set_texture
  defdelegate get_texture_rect(cs),         to: NIF, as: :rectangle_shape_get_texture_rect
  defdelegate set_texture_rect(cs,r),       to: NIF, as: :rectangle_shape_set_texture_rect
  defdelegate get_origin(cs),               to: NIF, as: :rectangle_shape_get_origin
  defdelegate set_origin(cs,o),             to: NIF, as: :rectangle_shape_set_origin
  defdelegate get_position(cs),             to: NIF, as: :rectangle_shape_get_position
  defdelegate set_position(cs,p),           to: NIF, as: :rectangle_shape_set_position
  defdelegate get_rotation(cs),             to: NIF, as: :rectangle_shape_get_rotation
  defdelegate set_rotation(cs,r),           to: NIF, as: :rectangle_shape_set_rotation
  defdelegate get_scale(cs),                to: NIF, as: :rectangle_shape_get_scale
  defdelegate set_scale(cs,s),              to: NIF, as: :rectangle_shape_set_scale
  defdelegate get_outline_color(cs),        to: NIF, as: :rectangle_shape_get_outline_color
  defdelegate set_outline_color(cs,c),      to: NIF, as: :rectangle_shape_set_outline_color
  defdelegate get_fill_color(cs),           to: NIF, as: :rectangle_shape_get_fill_color
  defdelegate set_fill_color(cs,c),         to: NIF, as: :rectangle_shape_set_fill_color
  defdelegate move(cs,m),                   to: NIF, as: :rectangle_shape_move
  defdelegate rotate(cs,r),                 to: NIF, as: :rectangle_shape_rotate
  defdelegate scale(cs,s),                  to: NIF, as: :rectangle_shape_scale
  defdelegate flip(cs),                     to: NIF, as: :rectangle_shape_flip
  defdelegate flop(cs),                     to: NIF, as: :rectangle_shape_flop
  defdelegate get_global_bounds(cs),        to: NIF, as: :rectangle_shape_get_global_bounds
end
