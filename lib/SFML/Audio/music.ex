defmodule SFML.Audio.Music do
  alias SFML.Audio.NIF

  defdelegate create(),                     to: NIF, as: :music_create
  defdelegate open_from_file(f),            to: NIF, as: :music_open_from_file
  defdelegate discard(m),                   to: NIF, as: :music_discard
  defdelegate play(m),                      to: NIF, as: :music_play
  defdelegate pause(m),                     to: NIF, as: :music_pause
  defdelegate stop(m),                      to: NIF, as: :music_stop
  defdelegate get_channel_count(m),         to: NIF, as: :music_get_channel_count
  defdelegate get_sample_rate(m),           to: NIF, as: :music_get_sample_rate
  defdelegate get_playing_offset(m),        to: NIF, as: :music_get_playing_offset
  defdelegate set_playing_offset(m, time),  to: NIF, as: :music_set_playing_offset
  defdelegate get_loop(m),                  to: NIF, as: :music_get_loop
  defdelegate set_loop(m, loop),            to: NIF, as: :music_set_loop
  defdelegate get_volume(m),                to: NIF, as: :music_get_volume
  defdelegate set_volume(m, v),             to: NIF, as: :music_set_volume
  defdelegate get_pitch(m),                 to: NIF, as: :music_get_pitch
  defdelegate set_pitch(m, p),              to: NIF, as: :music_set_pitch
  defdelegate get_attenuation(m),           to: NIF, as: :music_get_attenuation
  defdelegate set_attenuation(m, a),        to: NIF, as: :music_set_attenuation
end
