// Graphics.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include "eSoundBuffer.h"
#include "eSound.h"
#include "eMusic.h"

int load(ErlNifEnv *env, void **priv_data, ERL_NIF_TERM load_info)
{
    ResSoundBuffer::Define(env, "sfml_soundbuffer");
    ResSound::Define(env, "sfml_sound");
    ResMusic::Define(env, "sfml_music");
    return 0;
}

// Let's define the array of ErlNifFunc beforehand: 
static ErlNifFunc nif_funcs[] = {
    // {erl_function_name, erl_function_arity, c_function} 
    { "soundbuffer_load_from_file", 1, sfSoundBufferLoadFromFile },
    { "soundbuffer_discard",        1, sfSoundBufferDiscard      },
    { "soundbuffer_save_to_file",   2, sfSoundBufferSaveToFile   },

    { "sound_create",               0, sfSoundCreate             },
    { "sound_set_buffer",           2, sfSoundSetBuffer          },
    { "sound_discard",              1, sfSoundDiscard            },
    { "sound_play",                 1, sfSoundPlay               },
    { "sound_pause",                1, sfSoundPause              },
    { "sound_stop",                 1, sfSoundStop               },
    { "sound_get_playing_offset",   1, sfSoundGetPlayingOffset   },
    { "sound_set_playing_offset",   2, sfSoundSetPlayingOffset   },
    { "sound_get_loop",             1, sfSoundGetLoop            },
    { "sound_set_loop",             2, sfSoundSetLoop            },
    { "sound_get_volume",           1, sfSoundGetVolume          },
    { "sound_set_volume",           2, sfSoundSetVolume          },
    { "sound_get_pitch",            1, sfSoundGetPitch           },
    { "sound_set_pitch",            2, sfSoundSetPitch           },
    { "sound_get_attenuation",      1, sfSoundGetAttenuation     },
    { "sound_set_attenuation",      2, sfSoundSetAttenuation     },

    { "music_create",               0, sfMusicCreate             },
    { "music_open_from_file",       1, sfMusicOpenFromFile       },
    { "music_discard",              1, sfMusicDiscard            },
    { "music_play",                 1, sfMusicPlay               },
    { "music_pause",                1, sfMusicPause              },
    { "music_stop",                 1, sfMusicStop               },
    { "music_get_channel_count",    1, sfMusicGetChannelCount    },
    { "music_get_sample_rate",      1, sfMusicGetSampleRate      },
    { "music_get_playing_offset",   1, sfMusicGetPlayingOffset   },
    { "music_set_playing_offset",   2, sfMusicSetPlayingOffset   },
    { "music_get_loop",             1, sfMusicGetLoop            },
    { "music_set_loop",             2, sfMusicSetLoop            },
    { "music_get_volume",           1, sfMusicGetVolume          },
    { "music_set_volume",           2, sfMusicSetVolume          },
    { "music_get_pitch",            1, sfMusicGetPitch           },
    { "music_set_pitch",            2, sfMusicSetPitch           },
    { "music_get_attenuation",      1, sfMusicGetAttenuation     },
    { "music_set_attenuation",      2, sfMusicSetAttenuation     },
};

ERL_NIF_INIT(Elixir.SFML.Audio.NIF, nif_funcs, load, NULL, NULL, NULL);
