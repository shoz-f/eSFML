#pragma once

#include <SFML/Audio.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::Sound> ResSound;

DECL_NIF(sfSoundCreate);
DECL_NIF(sfSoundDiscard);
DECL_NIF(sfSoundPlay);
DECL_NIF(sfSoundPause);
DECL_NIF(sfSoundStop);
DECL_NIF(sfSoundGetPlayingOffset);
DECL_NIF(sfSoundSetPlayingOffset);
DECL_NIF(sfSoundGetLoop);
DECL_NIF(sfSoundSetLoop);
DECL_NIF(sfSoundGetVolume);
DECL_NIF(sfSoundSetVolume);
DECL_NIF(sfSoundGetPitch);
DECL_NIF(sfSoundSetPitch);
DECL_NIF(sfSoundGetAttenuation);
DECL_NIF(sfSoundSetAttenuation);
