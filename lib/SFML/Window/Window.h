#pragma once

#include <SFML/Graphics.hpp>

void sfWindowClose(sf::Window* win);

bool sfWindowIsOpen(sf::Window* win);

void sfWindowDisplay(sf::Window* win);

bool sfWindowPollEvent(sf::Window*win, sf::Event* event);

