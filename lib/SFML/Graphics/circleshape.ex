defmodule SFML.Graphics.CircleShape do
  alias SFML.Graphics.NIF
  alias __MODULE__

  defstruct [:handle]

  def create(),                                              do: %CircleShape{handle: NIF.circle_shape_create()}
  def destroy(%CircleShape{handle: h}=cs),                   do: NIF.circle_shape_destroy(h)
  def get_radius(%CircleShape{handle: h}=cs),                do: NIF.circle_shape_get_radius(h)
  def set_radius(%CircleShape{handle: h}=cs, r),             do: NIF.circle_shape_set_radius(h, r)
  def get_point(%CircleShape{handle: h}=cs),                 do: NIF.circle_shape_get_point(h)
  def get_outline_thickness(%CircleShape{handle: h}=cs),     do: NIF.circle_shape_get_outline_thickness(h)
  def set_outline_thickness(%CircleShape{handle: h}=cs, t),  do: NIF.circle_shape_set_outline_thickness(h, t)
  def set_texture(%CircleShape{handle: h}=cs, t),            do: NIF.circle_shape_set_texture(h, t)
  def get_texture_rect(%CircleShape{handle: h}=cs),          do: NIF.circle_shape_get_texture_rect(h)
  def set_texture_rect(%CircleShape{handle: h}=cs, r),       do: NIF.circle_shape_set_texture_rect(h, r)
  def get_origin(%CircleShape{handle: h}=cs),                do: NIF.circle_shape_get_origin(h)
  def set_origin(%CircleShape{handle: h}=cs, o),             do: NIF.circle_shape_set_origin(h, o)
  def get_position(%CircleShape{handle: h}=cs),              do: NIF.circle_shape_get_position(h)
  def set_position(%CircleShape{handle: h}=cs, p),           do: NIF.circle_shape_set_position(h, p)
  def get_rotation(%CircleShape{handle: h}=cs),              do: NIF.circle_shape_get_rotation(h)
  def set_rotation(%CircleShape{handle: h}=cs, r),           do: NIF.circle_shape_set_rotation(h, r)
  def get_scale(%CircleShape{handle: h}=cs),                 do: NIF.circle_shape_get_scale(h)
  def set_scale(%CircleShape{handle: h}=cs, s),              do: NIF.circle_shape_set_scale(h, s)
  def get_outline_color(%CircleShape{handle: h}=cs),         do: NIF.circle_shape_get_outline_color(h)
  def set_outline_color(%CircleShape{handle: h}=cs, c),      do: NIF.circle_shape_set_outline_color(h, c)
  def get_fill_color(%CircleShape{handle: h}=cs),            do: NIF.circle_shape_get_fill_color(h)
  def set_fill_color(%CircleShape{handle: h}=cs, c),         do: NIF.circle_shape_set_fill_color(h, c)
  def move(%CircleShape{handle: h}=cs, m),                   do: NIF.circle_shape_move(h, m)
  def rotate(%CircleShape{handle: h}=cs, r),                 do: NIF.circle_shape_rotate(h, r)
  def scale(%CircleShape{handle: h}=cs, s),                  do: NIF.circle_shape_scale(h, s)
  def flip(%CircleShape{handle: h}=cs),                      do: NIF.circle_shape_flip(h)
  def flop(%CircleShape{handle: h}=cs),                      do: NIF.circle_shape_flop(h)
  def get_global_bounds(%CircleShape{handle: h}=cs),         do: NIF.circle_shape_get_global_bounds(h)
end
