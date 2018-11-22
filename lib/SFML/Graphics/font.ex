defmodule SFML.Graphics.Font do
  alias SFML.Graphics.NIF

  defdelegate load_from_file(file), to: NIF, as: :font_load_from_file
end
