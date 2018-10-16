defmodule SFML.Audio.SoundBuffer do
  alias SFML.Audio.NIF

  defdelegate load_from_file(f),    to: NIF, as: :soundbuffer_load_from_file
  defdelegate discard(s),           to: NIF, as: :soundbuffer_discard
  defdelegate save_to_file(s, f),   to: NIF, as: :soundbuffer_save_to_file
end
