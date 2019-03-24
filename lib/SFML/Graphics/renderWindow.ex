defmodule SFML.Graphics.RenderWindow do
  alias SFML.Graphics.NIF

  defdelegate create(size, title),                to: NIF, as: :render_window_create
  defdelegate destroy(w),                         to: NIF, as: :render_window_destroy
  defdelegate clear(w, color \\ :Black),          to: NIF, as: :render_window_clear
  defdelegate draw(w, entity),                    to: NIF, as: :render_window_draw
  defdelegate drawvertex(w, vertices, primitive), to: NIF, as: :render_window_draw_vertices
  defdelegate set_framerate_limit(w, limit),      to: NIF, as: :render_window_set_framerate_limit
  defdelegate display(w),                         to: NIF, as: :render_window_display
  defdelegate get_size(w),                        to: NIF, as: :render_window_get_size
  defdelegate is_open(w),                         to: NIF, as: :render_window_is_open
  defdelegate poll_event(w),                      to: NIF, as: :render_window_poll_event
  defdelegate request_focus(w),                   to: NIF, as: :render_window_request_focus
end
