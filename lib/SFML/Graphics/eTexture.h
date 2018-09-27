#pragma once

#include <SFML/Graphics.hpp>
#include <erl_nif.h>
#include "NifRes.h"

typedef NifRes<sf::Texture> ResTexture;

ERL_NIF_TERM sfTextureLoadFromFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfTextureGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
