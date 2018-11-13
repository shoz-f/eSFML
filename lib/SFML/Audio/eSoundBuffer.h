#ifndef _ESOUNDBUFFER_H
#define _ESOUNDBUFFER_H

#include <SFML/Audio.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::SoundBuffer,false> ResSoundBuffer;

DECL_NIF(sfSoundBufferLoadFromFile);
DECL_NIF(sfSoundBufferDiscard);
DECL_NIF(sfSoundBufferSaveToFile);

#endif
