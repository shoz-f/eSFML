#pragma once

#include <SFML/Audio.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::SoundBuffer> ResSoundBuffer;

DECL_NIF(sfSoundBufferLoadFromFile);
DECL_NIF(sfSoundBufferDiscard);
DECL_NIF(sfSoundBufferSaveToFile);
