#ifndef _ECLOCK_H
#define _ECLOCK_H

#include <SFML/System/Clock.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::Clock> ResClock;

ERL_NIF_TERM sfClockCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfClockRelease(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfClockGetElapsedTime(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfClockRestart(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfClockInterval(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfGClockGetElapsedTime);
DECL_NIF(sfGClockRestart);

#endif