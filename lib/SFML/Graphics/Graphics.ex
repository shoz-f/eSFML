defmodule SFML.Graphics.NIF do
  @on_load :load_nifs
  def load_nifs do
    :erlang.load_nif(__DIR__ <> "/GraphicsNIF", 0)
  end

  def render_window_create(_a, _b),              do: raise "NIF render_window/2 not implemented"
  def render_window_destroy(_a),                 do: raise "NIF render_window_destroy/1 not implemented"
  def render_window_clear(_a, _b),               do: raise "NIF render_window_clear/1 not implemented"
  def render_window_draw(_a, _b),                do: raise "NIF render_window_draw/2 not implemented"
  def render_window_set_framerate_limit(_a, _b), do: raise "NIF render_window_set_framerate_limit/2 not implemented"
  def render_window_display(_a),                 do: raise "NIF render_window_display/1 not implemented"
  def render_window_get_size(_a),                do: raise "NIF render_window_get_size/1 not implemented"
  def render_window_is_open(_a),                 do: raise "NIF render_window_is_open/1 not implemented"
  def render_window_poll_event(_a),              do: raise "NIF render_window_pool_event/1 not implemented"
  def render_window_request_focus(_a),           do: raise "NIF render_window_request_focus/1 not implemented"
                                                 
  def circle_shape_create(),                     do: raise "NIF circle_shape/0 not implemented"
  def circle_shape_destroy(_a),                  do: raise "NIF circle_shape_destroy/1 not implemented"
  def circle_shape_set_radius(_a, _b),           do: raise "NIF circle_shape_set_radius/2 not implemented"
  def circle_shape_set_fillcolor(_a, _b),        do: raise "NIF circle_shape_set_fillcolor/2 not implemented"
                                                 
  def sprite_create(_a),                         do: raise "NIF sprite/0 not implemented"
  def sprite_clone(_a),                          do: raise "NIF sprite/0 not implemented"
  def sprite_set_texture(_a, _b),                do: raise "NIF sprite_set_texture/2 not implemented"
  def sprite_set_texture_rect(_a, _b),           do: raise "NIF sprite_set_texture_rect/2 not implemented"
  def sprite_get_texture_rect(_a),               do: raise "NIF sprite_set_texture_rect/2 not implemented"
  def sprite_get_position(_a),                   do: raise "NIF sprite_get_position/1 not implemented"
  def sprite_set_position(_a, _b),               do: raise "NIF sprite_set_position/2 not implemented"
  def sprite_get_rotation(_a),                   do: raise "NIF sprite_get_rotation/1 not implemented"
  def sprite_set_rotation(_a, _b),               do: raise "NIF sprite_set_rotation/2 not implemented"
  def sprite_get_scale(_a),                      do: raise "NIF sprite_get_scale/1 not implemented"
  def sprite_set_scale(_a, _b),                  do: raise "NIF sprite_set_scale/2 not implemented"
  def sprite_get_color(_a),                      do: raise "NIF sprite_get_scale/1 not implemented"
  def sprite_set_color(_a, _b),                  do: raise "NIF sprite_set_scale/2 not implemented"
  def sprite_move(_a, _b),                       do: raise "NIF sprite_move/2 not implemented"
  def sprite_rotate(_a, _b),                     do: raise "NIF sprite_rotate/2 not implemented"
  def sprite_scale(_a, _b),                      do: raise "NIF sprite_scale/2 not implemented"
  def sprite_flip(_a),                           do: raise "NIF sprite_flip/1 not implemented"
  def sprite_get_global_bounds(_a),              do: raise "NIF sprite_get_global_bounds/1 not implemented"
                                                 
  def texture_load_from_file(_a),                do: raise "NIF texture_load_from_file/1 not implemented"
  def texture_get_size(_a),                      do: raise "NIF texture_get_size/1 not implemented"
end
                                    