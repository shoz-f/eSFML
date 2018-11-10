#ifndef _EDRAWABLE_H
#define _EDRAWABLE_H

#include <SFML/Graphics.hpp>
#include "ErlNifEx.h"

typedef NifRes<sf::Drawable, true> ResDrawable;

extern sf::Mutex mutexGL;

#endif