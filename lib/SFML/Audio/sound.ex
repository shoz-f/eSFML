defmodule SFML.Audio.Sound do
  alias SFML.Audio.NIF

  defdelegate create(),                     to: NIF, as: :sound_create
  defdelegate set_buffer(s, b),             to: NIF, as: :sound_set_buffer
  defdelegate discard(s),                   to: NIF, as: :sound_discard
  defdelegate play(s),                      to: NIF, as: :sound_play
  defdelegate pause(s),                     to: NIF, as: :sound_pause
  defdelegate stop(s),                      to: NIF, as: :sound_stop
  defdelegate get_playing_offset(s),        to: NIF, as: :sound_get_playing_offset
  defdelegate set_playing_offset(s, time),  to: NIF, as: :sound_set_playing_offset
  defdelegate get_loop(s),                  to: NIF, as: :sound_get_loop
  defdelegate set_loop(s, loop),            to: NIF, as: :sound_set_loop
  defdelegate get_volume(s),                to: NIF, as: :sound_get_volume
  defdelegate set_volume(s, v),             to: NIF, as: :sound_set_volume
  defdelegate get_pitch(s),                 to: NIF, as: :sound_get_pitch
  defdelegate set_pitch(s, p),              to: NIF, as: :sound_set_pitch
  defdelegate get_attenuation(s),           to: NIF, as: :sound_get_attenuation
  defdelegate set_attenuation(s, a),        to: NIF, as: :sound_set_attenuation
end
