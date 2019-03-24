defmodule Loop do
  def loop(c, s) when s > 30.0 do
    s
  end
  def loop(c, _) do
    s = SFML.System.clock_get_elapsed_time(c)
    loop(c, s)
  end
end
