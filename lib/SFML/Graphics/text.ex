defmodule SFML.Graphics.Text do
  alias SFML.Graphics.NIF

  defdelegate create(tx,f),                 to: NIF, as: :text_create
  defdelegate destroy(tx),                  to: NIF, as: :text_destroy
  defdelegate set_character_size(tx,s),     to: NIF, as: :text_set_character_size
  defdelegate set_letter_spacing(tx,s),     to: NIF, as: :text_set_letter_spacing
  defdelegate set_line_spacing(tx,s),       to: NIF, as: :text_set_line_spacing
  defdelegate set_style(tx,s),              to: NIF, as: :text_set_style
  defdelegate set_color(tx,c),              to: NIF, as: :text_set_color
  defdelegate get_outline_thickness(tx),    to: NIF, as: :text_get_outline_thickness
  defdelegate set_outline_thickness(tx,t),  to: NIF, as: :text_set_outline_thickness
  defdelegate set_texture(tx,t),            to: NIF, as: :text_set_texture
  defdelegate get_texture_rect(tx),         to: NIF, as: :text_get_texture_rect
  defdelegate set_texture_rect(tx,r),       to: NIF, as: :text_set_texture_rect
  defdelegate get_origin(tx),               to: NIF, as: :text_get_origin
  defdelegate set_origin(tx,o),             to: NIF, as: :text_set_origin
  defdelegate get_position(tx),             to: NIF, as: :text_get_position
  defdelegate set_position(tx,p),           to: NIF, as: :text_set_position
  defdelegate get_rotation(tx),             to: NIF, as: :text_get_rotation
  defdelegate set_rotation(tx,r),           to: NIF, as: :text_set_rotation
  defdelegate get_scale(tx),                to: NIF, as: :text_get_scale
  defdelegate set_scale(tx,s),              to: NIF, as: :text_set_scale
  defdelegate get_outline_color(tx),        to: NIF, as: :text_get_outline_color
  defdelegate set_outline_color(tx,c),      to: NIF, as: :text_set_outline_color
  defdelegate get_fill_color(tx),           to: NIF, as: :text_get_fill_color
  defdelegate set_fill_color(tx,c),         to: NIF, as: :text_set_fill_color
  defdelegate move(tx,m),                   to: NIF, as: :text_move
  defdelegate rotate(tx,r),                 to: NIF, as: :text_rotate
  defdelegate scale(tx,s),                  to: NIF, as: :text_scale
  defdelegate get_global_bounds(tx),        to: NIF, as: :text_get_global_bounds
end
