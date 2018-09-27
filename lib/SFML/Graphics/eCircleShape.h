#pragma once

#include "eDrawable.h"

typedef NifResChild<sf::CircleShape, ResDrawable> ResCircleShape;

ERL_NIF_TERM sfCircleShapeCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfCircleShapeDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfCircleShapeSetRadius(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfCircleShapeSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
