#ifndef _EMUSIC_H
#define _EMUSIC_H

#include <SFML/Audio.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::Music> ResMusic;

DECL_NIF(sfMusicCreate);
DECL_NIF(sfMusicDiscard);
DECL_NIF(sfMusicOpenFromFile);
DECL_NIF(sfMusicPlay);
DECL_NIF(sfMusicPause);
DECL_NIF(sfMusicStop);
DECL_NIF(sfMusicGetChannelCount);
DECL_NIF(sfMusicGetSampleRate);
DECL_NIF(sfMusicGetPlayingOffset);
DECL_NIF(sfMusicSetPlayingOffset);
DECL_NIF(sfMusicGetLoop);
DECL_NIF(sfMusicSetLoop);
DECL_NIF(sfMusicGetVolume);
DECL_NIF(sfMusicSetVolume);
DECL_NIF(sfMusicGetPitch);
DECL_NIF(sfMusicSetPitch);
DECL_NIF(sfMusicGetAttenuation);
DECL_NIF(sfMusicSetAttenuation);

#endif
