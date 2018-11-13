defmodule SFML.Audio.NIF do
  @on_load :load_nifs
  def load_nifs do
    :erlang.load_nif(
      __DIR__ <> case :os.type do
        {:win32,_} -> "/AudioNIF"
        {:unix,_}  -> "/libAudioNIF"
        {_,_}      -> "/UnknownOS"
      end,
      0
    ) 
  end

  def soundbuffer_load_from_file(_1),            do: raise "NIF soundbuffer_load_from_file/1 not implemented"
  def soundbuffer_discard(_1),                   do: raise "NIF soundbuffer_discard/1 not implemented"
  def soundbuffer_save_to_file(_1, _2),          do: raise "NIF soundbuffer_save_to_file/2 not implemented"

  def sound_create(),                            do: raise "NIF sound_create/0 not implemented"
  def sound_set_buffer(_1, _2),                  do: raise "NIF sound_set_buffer/2 not implemented"
  def sound_discard(_1),                         do: raise "NIF sound_discard/1 not implemented"
  def sound_play(_1),                            do: raise "NIF sound_play/1 not implemented"
  def sound_pause(_1),                           do: raise "NIF sound_pause/1 not implemented"
  def sound_stop(_1),                            do: raise "NIF sound_stop/1 not implemented"
  def sound_get_playing_offset(_1),              do: raise "NIF sound_get_playing_offset/1 not implemented"
  def sound_set_playing_offset(_1, _2),          do: raise "NIF sound_set_playing_offset/2 not implemented"
  def sound_get_loop(_1),                        do: raise "NIF sound_get_loop/1 not implemented"
  def sound_set_loop(_1, _2),                    do: raise "NIF sound_set_loop/2 not implemented"
  def sound_get_volume(_1),                      do: raise "NIF sound_get_volume/1 not implemented"
  def sound_set_volume(_1, _2),                  do: raise "NIF sound_set_volume/2 not implemented"
  def sound_get_pitch(_1),                       do: raise "NIF sound_get_pitch/1 not implemented"
  def sound_set_pitch(_1, _2),                   do: raise "NIF sound_set_pitch/2 not implemented"
  def sound_get_attenuation(_1),                 do: raise "NIF sound_get_attenuation/1 not implemented"
  def sound_set_attenuation(_1, _2),             do: raise "NIF sound_set_attenuation/2 not implemented"

  def music_create(),                            do: raise "NIF music_create/0 not implemented"
  def music_open_from_file(_1),                  do: raise "NIF music_open_from_file/1 not implemented"
  def music_discard(_a),                         do: raise "NIF music_discard/1 not implemented"
  def music_play(_1),                            do: raise "NIF music_play/1 not implemented"
  def music_pause(_1),                           do: raise "NIF music_pause/1 not implemented"
  def music_stop(_1),                            do: raise "NIF music_stop/1 not implemented"
  def music_get_channel_count(_1),               do: raise "NIF music_get_channel_count/1 not implemented"
  def music_get_sample_rate(_1),                 do: raise "NIF music_get_sample_rate/1 not implemented"
  def music_get_playing_offset(_1),              do: raise "NIF music_get_playing_offset/1 not implemented"
  def music_set_playing_offset(_1, _2),          do: raise "NIF music_set_playing_offset/2 not implemented"
  def music_get_loop(_1),                        do: raise "NIF music_get_loop/1 not implemented"
  def music_set_loop(_1, _2),                    do: raise "NIF music_set_loop/2 not implemented"
  def music_get_volume(_1),                      do: raise "NIF music_get_volume/1 not implemented"
  def music_set_volume(_1, _2),                  do: raise "NIF music_set_volume/2 not implemented"
  def music_get_pitch(_1),                       do: raise "NIF music_get_pitch/1 not implemented"
  def music_set_pitch(_1, _2),                   do: raise "NIF music_set_pitch/2 not implemented"
  def music_get_attenuation(_1),                 do: raise "NIF music_get_attenuation/1 not implemented"
  def music_set_attenuation(_1, _2),             do: raise "NIF music_set_attenuation/2 not implemented"
end
