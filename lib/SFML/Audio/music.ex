defmodule SFML.Audio.Music do
  alias SFML.Audio.NIF

  defdelegate create(),             to: NIF, as: :music_create
  defdelegate open_from_file(f),    to: NIF, as: :music_open_from_file
  defdelegate discard(m),           to: NIF, as: :music_discard
  defdelegate play(m),              to: NIF, as: :music_play
  defdelegate pause(m),             to: NIF, as: :music_pause
  defdelegate stop(m),              to: NIF, as: :music_stop
  defdelegate set_loop(m, loop),    to: NIF, as: :music_set_loop
end
