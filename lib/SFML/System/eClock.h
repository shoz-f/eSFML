#ifndef _ECLOCK_H
#define _ECLOCK_H

#include <SFML/System/Clock.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::Clock> ResClock;

DECL_NIF(sfClockCreate);
DECL_NIF(sfClockRelease);
DECL_NIF(sfClockGetElapsedTime);
DECL_NIF(sfClockRestart);
DECL_NIF(sfClockInterval);
DECL_NIF(sfGClockGetElapsedTime);
DECL_NIF(sfGClockRestart);

#endif