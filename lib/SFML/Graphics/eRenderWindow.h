#pragma once

#include <SFML/Graphics.hpp>
#include <erl_nif.h>
#include "NifRes.h"

typedef NifRes<sf::RenderWindow> ResRenderWindow;

ERL_NIF_TERM sfRenderWindowCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowClear(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDraw(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDisplay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowIsOpen(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowPollEvent(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowRequestFocus(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
