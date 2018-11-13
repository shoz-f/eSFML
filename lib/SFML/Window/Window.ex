defmodule SFML.Window.NIF do
  @on_load :load_nifs
  def load_nifs do
    :erlang.load_nif(
      __DIR__ <> case :os.type do
        {:win32,_} -> "/WindowNIF"
        {:unix,_}  -> "/libWindowNIF"
        {_,_}      -> "/UnknownOS"
      end,
      0
    ) 
  end

  def window_display(_a), do: raise "NIF render_window_display/1 not implemented"
end
