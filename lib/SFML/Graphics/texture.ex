defmodule SFML.Graphics.Texture do
  alias SFML.Graphics.NIF

  defdelegate load_from_file(file), to: NIF, as: :texture_load_from_file
  defdelegate get_size(t),          to: NIF, as: :texture_get_size
end
