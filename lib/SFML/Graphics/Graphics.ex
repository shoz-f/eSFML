defmodule SFML.Graphics.NIF do
  @on_load :load_nifs
  def load_nifs do
    :erlang.load_nif(
        __DIR__ <> case :os.type do
            {:win32,_} -> "/GraphicsNIF"
            {:unix,_}  -> "/libGraphicsNIF"
            {_,_}      -> "/UnknownOS"
        end,
        0
    )
  end

  def render_window_create(_a, _b),                 do: raise "NIF render_window/2 not implemented"
  def render_window_destroy(_a),                    do: raise "NIF render_window_destroy/1 not implemented"
  def render_window_clear(_a, _b),                  do: raise "NIF render_window_clear/1 not implemented"
  def render_window_draw(_a, _b),                   do: raise "NIF render_window_draw/2 not implemented"
  def render_window_draw_vertices(_a, _b, _c),      do: raise "NIF render_window_draw_vertices/3 not implemented"
  def render_window_set_framerate_limit(_a, _b),    do: raise "NIF render_window_set_framerate_limit/2 not implemented"
  def render_window_display(_a),                    do: raise "NIF render_window_display/1 not implemented"
  def render_window_get_size(_a),                   do: raise "NIF render_window_get_size/1 not implemented"
  def render_window_is_open(_a),                    do: raise "NIF render_window_is_open/1 not implemented"
  def render_window_poll_event(_a),                 do: raise "NIF render_window_pool_event/1 not implemented"
  def render_window_request_focus(_a),              do: raise "NIF render_window_request_focus/1 not implemented"

  def circle_shape_create(),                        do: raise "NIF circle_shape/0 not implemented"
  def circle_shape_destroy(_1),                     do: raise "NIF circle_shape_destroy/1 not implemented"
  def circle_shape_get_radius(_1),                  do: raise "NIF circle_shape_get_radius/1 not implemented"
  def circle_shape_set_radius(_1, _2),              do: raise "NIF circle_shape_set_radius/2 not implemented"
  def circle_shape_get_point(_1),                   do: raise "NIF circle_shape_get_point/1 not implemented"
  def circle_shape_get_outline_thickness(_1),       do: raise "NIF circle_shape_get_outline_thickness/1 not implemented"
  def circle_shape_set_outline_thickness(_1,_2),    do: raise "NIF circle_shape_set_outline_thickness/2 not implemented"
  def circle_shape_set_texture(_1,_2),              do: raise "NIF circle_shape_set_texture/2 not implemented"
  def circle_shape_get_texture_rect(_1),            do: raise "NIF circle_shape_get_texture_rect/1 not implemented"
  def circle_shape_set_texture_rect(_1,_2),         do: raise "NIF circle_shape_set_texture_rect/2 not implemented"
  def circle_shape_get_origin(_1),                  do: raise "NIF circle_shape_get_origin/1 not implemented"
  def circle_shape_set_origin(_1,_2),               do: raise "NIF circle_shape_set_origin/2 not implemented"
  def circle_shape_get_position(_1),                do: raise "NIF circle_shape_get_position/1 not implemented"
  def circle_shape_set_position(_1,_2),             do: raise "NIF circle_shape_set_position/2 not implemented"
  def circle_shape_get_rotation(_1),                do: raise "NIF circle_shape_get_rotation/1 not implemented"
  def circle_shape_set_rotation(_1,_2),             do: raise "NIF circle_shape_set_rotation/2 not implemented"
  def circle_shape_get_scale(_1),                   do: raise "NIF circle_shape_get_scale/1 not implemented"
  def circle_shape_set_scale(_1,_2),                do: raise "NIF circle_shape_get_scale/2 not implemented"
  def circle_shape_get_outline_color(_1),           do: raise "NIF circle_shape_get_outline_color/1 not implemented"
  def circle_shape_set_outline_color(_1,_2),        do: raise "NIF circle_shape_set_outline_color/2 not implemented"
  def circle_shape_get_fill_color(_1),              do: raise "NIF circle_shape_get_fill_color/1 not implemented"
  def circle_shape_set_fill_color(_1,_2),           do: raise "NIF circle_shape_set_fill_color/2 not implemented"
  def circle_shape_move(_1,_2),                     do: raise "NIF circle_shape_move/2 not implemented"
  def circle_shape_rotate(_1,_2),                   do: raise "NIF circle_shape_rotate/2 not implemented"
  def circle_shape_scale(_1,_2),                    do: raise "NIF circle_shape_scale/2 not implemented"
  def circle_shape_flip(_1),                        do: raise "NIF circle_shape_flip/1 not implemented"
  def circle_shape_flop(_1),                        do: raise "NIF circle_shape_flop/1 not implemented"
  def circle_shape_get_global_bounds(_1),           do: raise "NIF circle_shape_get_global_bounds/1 not implemented"

  def rectangle_shape_create(),                     do: raise "NIF rectangle_shape/0 not implemented"
  def rectangle_shape_destroy(_1),                  do: raise "NIF rectangle_shape_destroy/1 not implemented"
  def rectangle_shape_get_size(_1),                 do: raise "NIF rectangle_shape_get_size/1 not implemented"
  def rectangle_shape_set_size(_1, _2),             do: raise "NIF rectangle_shape_set_size/2 not implemented"
  def rectangle_shape_get_point(_1),                do: raise "NIF rectangle_shape_get_point/1 not implemented"
  def rectangle_shape_get_outline_thickness(_1),    do: raise "NIF rectangle_shape_get_outline_thickness/1 not implemented"
  def rectangle_shape_set_outline_thickness(_1,_2), do: raise "NIF rectangle_shape_set_outline_thickness/2 not implemented"
  def rectangle_shape_set_texture(_1,_2),           do: raise "NIF rectangle_shape_set_texture/2 not implemented"
  def rectangle_shape_get_texture_rect(_1),         do: raise "NIF rectangle_shape_get_texture_rect/1 not implemented"
  def rectangle_shape_set_texture_rect(_1,_2),      do: raise "NIF rectangle_shape_set_texture_rect/2 not implemented"
  def rectangle_shape_get_origin(_1),               do: raise "NIF rectangle_shape_get_origin/1 not implemented"
  def rectangle_shape_set_origin(_1,_2),            do: raise "NIF rectangle_shape_set_origin/2 not implemented"
  def rectangle_shape_get_position(_1),             do: raise "NIF rectangle_shape_get_position/1 not implemented"
  def rectangle_shape_set_position(_1,_2),          do: raise "NIF rectangle_shape_set_position/2 not implemented"
  def rectangle_shape_get_rotation(_1),             do: raise "NIF rectangle_shape_get_rotation/1 not implemented"
  def rectangle_shape_set_rotation(_1,_2),          do: raise "NIF rectangle_shape_set_rotation/2 not implemented"
  def rectangle_shape_get_scale(_1),                do: raise "NIF rectangle_shape_get_scale/1 not implemented"
  def rectangle_shape_set_scale(_1,_2),             do: raise "NIF rectangle_shape_get_scale/2 not implemented"
  def rectangle_shape_get_outline_color(_1),        do: raise "NIF rectangle_shape_get_outline_color/1 not implemented"
  def rectangle_shape_set_outline_color(_1,_2),     do: raise "NIF rectangle_shape_set_outline_color/2 not implemented"
  def rectangle_shape_get_fill_color(_1),           do: raise "NIF rectangle_shape_get_fill_color/1 not implemented"
  def rectangle_shape_set_fill_color(_1,_2),        do: raise "NIF rectangle_shape_set_fill_color/2 not implemented"
  def rectangle_shape_move(_1,_2),                  do: raise "NIF rectangle_shape_move/2 not implemented"
  def rectangle_shape_rotate(_1,_2),                do: raise "NIF rectangle_shape_rotate/2 not implemented"
  def rectangle_shape_scale(_1,_2),                 do: raise "NIF rectangle_shape_scale/2 not implemented"
  def rectangle_shape_flip(_1),                     do: raise "NIF rectangle_shape_flip/1 not implemented"
  def rectangle_shape_flop(_1),                     do: raise "NIF rectangle_shape_flop/1 not implemented"
  def rectangle_shape_get_global_bounds(_1),        do: raise "NIF rectangle_shape_get_global_bounds/1 not implemented"

  def convex_shape_create(_1),                      do: raise "NIF convex_shape_create/1 not implemented"
  def convex_shape_get_point_count(_1),             do: raise "NIF convex_shape_get_point_count/1 not implemented"
  def convex_shape_get_point(_1),                   do: raise "NIF convex_shape_get_point/1 not implemented"
  def convex_shape_get_outline_thickness(_1),       do: raise "NIF convex_shape_get_outline_thickness/1 not implemented"
  def convex_shape_set_outline_thickness(_1,_2),    do: raise "NIF convex_shape_set_outline_thickness/2 not implemented"
  def convex_shape_set_texture(_1,_2),              do: raise "NIF convex_shape_set_texture/2 not implemented"
  def convex_shape_get_texture_rect(_1),            do: raise "NIF convex_shape_get_texture_rect/1 not implemented"
  def convex_shape_set_texture_rect(_1,_2),         do: raise "NIF convex_shape_set_texture_rect/2 not implemented"
  def convex_shape_get_origin(_1),                  do: raise "NIF convex_shape_get_origin/1 not implemented"
  def convex_shape_set_origin(_1,_2),               do: raise "NIF convex_shape_set_origin/2 not implemented"
  def convex_shape_get_position(_1),                do: raise "NIF convex_shape_get_position/1 not implemented"
  def convex_shape_set_position(_1,_2),             do: raise "NIF convex_shape_set_position/2 not implemented"
  def convex_shape_get_rotation(_1),                do: raise "NIF convex_shape_get_rotation/1 not implemented"
  def convex_shape_set_rotation(_1,_2),             do: raise "NIF convex_shape_set_rotation/2 not implemented"
  def convex_shape_get_scale(_1),                   do: raise "NIF convex_shape_get_scale/1 not implemented"
  def convex_shape_set_scale(_1,_2),                do: raise "NIF convex_shape_get_scale/2 not implemented"
  def convex_shape_get_outline_color(_1),           do: raise "NIF convex_shape_get_outline_color/1 not implemented"
  def convex_shape_set_outline_color(_1,_2),        do: raise "NIF convex_shape_set_outline_color/2 not implemented"
  def convex_shape_get_fill_color(_1),              do: raise "NIF convex_shape_get_fill_color/1 not implemented"
  def convex_shape_set_fill_color(_1,_2),           do: raise "NIF convex_shape_set_fill_color/2 not implemented"
  def convex_shape_move(_1,_2),                     do: raise "NIF convex_shape_move/2 not implemented"
  def convex_shape_rotate(_1,_2),                   do: raise "NIF convex_shape_rotate/2 not implemented"
  def convex_shape_scale(_1,_2),                    do: raise "NIF convex_shape_scale/2 not implemented"
  def convex_shape_flip(_1),                        do: raise "NIF convex_shape_flip/1 not implemented"
  def convex_shape_flop(_1),                        do: raise "NIF convex_shape_flop/1 not implemented"
  def convex_shape_get_global_bounds(_1),           do: raise "NIF convex_shape_get_global_bounds/1 not implemented"

  def sprite_create(_a),                            do: raise "NIF sprite/0 not implemented"
  def sprite_clone(_a),                             do: raise "NIF sprite/0 not implemented"
  def sprite_set_texture(_a, _b),                   do: raise "NIF sprite_set_texture/2 not implemented"
  def sprite_set_texture_rect(_a, _b),              do: raise "NIF sprite_set_texture_rect/2 not implemented"
  def sprite_get_texture_rect(_a),                  do: raise "NIF sprite_set_texture_rect/2 not implemented"
  def sprite_get_origin(_1),                        do: raise "NIF sprite_get_origin/1 not implemented"
  def sprite_set_origin(_1, _2),                    do: raise "NIF sprite_set_origin/2 not implemented"
  def sprite_get_position(_a),                      do: raise "NIF sprite_get_position/1 not implemented"
  def sprite_set_position(_a, _b),                  do: raise "NIF sprite_set_position/2 not implemented"
  def sprite_get_rotation(_a),                      do: raise "NIF sprite_get_rotation/1 not implemented"
  def sprite_set_rotation(_a, _b),                  do: raise "NIF sprite_set_rotation/2 not implemented"
  def sprite_get_scale(_a),                         do: raise "NIF sprite_get_scale/1 not implemented"
  def sprite_set_scale(_a, _b),                     do: raise "NIF sprite_set_scale/2 not implemented"
  def sprite_get_color(_a),                         do: raise "NIF sprite_get_scale/1 not implemented"
  def sprite_set_color(_a, _b),                     do: raise "NIF sprite_set_scale/2 not implemented"
  def sprite_move(_a, _b),                          do: raise "NIF sprite_move/2 not implemented"
  def sprite_rotate(_a, _b),                        do: raise "NIF sprite_rotate/2 not implemented"
  def sprite_scale(_a, _b),                         do: raise "NIF sprite_scale/2 not implemented"
  def sprite_flip(_a),                              do: raise "NIF sprite_flip/1 not implemented"
  def sprite_flop(_1),                              do: raise "NIF sprite_flop/1 not implemented"
  def sprite_get_global_bounds(_a),                 do: raise "NIF sprite_get_global_bounds/1 not implemented"

  def texture_load_from_file(_a),                   do: raise "NIF texture_load_from_file/1 not implemented"
  def texture_get_size(_a),                         do: raise "NIF texture_get_size/1 not implemented"

  def text_create(_1, _2),                          do: raise "NIF text/2 not implemented"
  def text_destroy(_1),                             do: raise "NIF text_destroy/1 not implemented"
  def text_set_character_size(_1,_2),               do: raise "NIF text_set_character_size/2 not implemented"
  def text_set_letter_spacing(_1,_2),               do: raise "NIF text_set_letter_spacing/2 not implemented"
  def text_set_line_spacing(_1,_2),                 do: raise "NIF text_set_line_spacing/2 not implemented"
  def text_set_style(_1,_2),                        do: raise "NIF text_set_style/2 not implemented"
  def text_set_color(_1,_2),                        do: raise "NIF text_set_color/2 not implemented"
  def text_get_outline_thickness(_1),               do: raise "NIF text_get_outline_thickness/1 not implemented"
  def text_set_outline_thickness(_1,_2),            do: raise "NIF text_set_outline_thickness/2 not implemented"
  def text_set_texture(_1,_2),                      do: raise "NIF text_set_texture/2 not implemented"
  def text_get_texture_rect(_1),                    do: raise "NIF text_get_texture_rect/1 not implemented"
  def text_set_texture_rect(_1,_2),                 do: raise "NIF text_set_texture_rect/2 not implemented"
  def text_get_origin(_1),                          do: raise "NIF text_get_origin/1 not implemented"
  def text_set_origin(_1,_2),                       do: raise "NIF text_set_origin/2 not implemented"
  def text_get_position(_1),                        do: raise "NIF text_get_position/1 not implemented"
  def text_set_position(_1,_2),                     do: raise "NIF text_set_position/2 not implemented"
  def text_get_rotation(_1),                        do: raise "NIF text_get_rotation/1 not implemented"
  def text_set_rotation(_1,_2),                     do: raise "NIF text_set_rotation/2 not implemented"
  def text_get_scale(_1),                           do: raise "NIF text_get_scale/1 not implemented"
  def text_set_scale(_1,_2),                        do: raise "NIF text_get_scale/2 not implemented"
  def text_get_outline_color(_1),                   do: raise "NIF text_get_outline_color/1 not implemented"
  def text_set_outline_color(_1,_2),                do: raise "NIF text_set_outline_color/2 not implemented"
  def text_get_fill_color(_1),                      do: raise "NIF text_get_fill_color/1 not implemented"
  def text_set_fill_color(_1,_2),                   do: raise "NIF text_set_fill_color/2 not implemented"
  def text_move(_1,_2),                             do: raise "NIF text_move/2 not implemented"
  def text_rotate(_1,_2),                           do: raise "NIF text_rotate/2 not implemented"
  def text_scale(_1,_2),                            do: raise "NIF text_scale/2 not implemented"
  def text_get_global_bounds(_1),                   do: raise "NIF text_get_global_bounds/1 not implemented"

  def font_load_from_file(_a),                      do: raise "NIF font_load_from_file/1 not implemented"

  def vertex_deque_create(_1),                      do: raise "NIF sfVertexDequeCreate/1 not implemented"
  def vertex_deque_destroy(_1),                     do: raise "NIF sfVertexDequeDestroy/1 not implemented"
  def vertex_deque_get_count(_1),                   do: raise "NIF sfVertexDequeGetCount/1 not implemented"
  def vertex_deque_set_pos(_1,_2,_3),               do: raise "NIF sfVertexDequeSetVertexPosition/3 not implemented"
  def vertex_deque_set_color(_1,_2,_3),             do: raise "NIF sfVertexDequeSetVertexColor/3 not implemented"
  def vertex_deque_get(_1,_2),                      do: raise "NIF sfVertexDequeGetVertex/2 not implemented"
  def vertex_deque_clear(_1),                       do: raise "NIF sfVertexDequeClear/1 not implemented"
  def vertex_deque_resize(_1,_2),                   do: raise "NIF sfVertexDequeResize/2 not implemented"
  def vertex_deque_push(_1,_2),                     do: raise "NIF sfVertexDequePush/2 not implemented"
  def vertex_deque_set_primitive_type(_1,_2),       do: raise "NIF sfVertexDequeSetPrimitiveType/2 not implemented"
  def vertex_deque_get_primitive_type(_1),          do: raise "NIF sfVertexDequeGetPrimitiveType/1 not implemented"

#  def transformable_move(_a, _b),                do: raise "NIF transformable_move/2 not implemented"
#  def transformable_rotate(_a, _b),              do: raise "NIF transformable_rotate/2 not implemented"
#  def transformable_scale(_a, _b),               do: raise "NIF transformable_scale/2 not implemented"
end

defmodule SFML.Graphics do
end
