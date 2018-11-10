#ifndef _EEVENT_H
#define _EEVENT_H

#include <SFML/Window/Event.hpp>
#include "ErlNifEx.h"

ERL_NIF_TERM enifMakeNoEvent(ErlNifEnv* env);
ERL_NIF_TERM enifMakeEvent(ErlNifEnv* env, sf::Event& event);

#endif
