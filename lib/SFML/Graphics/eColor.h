#pragma once

#include <SFML/Graphics/Color.hpp>
#include <map>
#include <string>

const std::map<std::string, sf::Color> cColorMap = {
    { "Black",       sf::Color::Black       },
    { "White",       sf::Color::White       },
    { "Red",         sf::Color::Red         },
    { "Green",       sf::Color::Green       },
    { "Blue",        sf::Color::Blue        },
    { "Yellow",      sf::Color::Yellow      },
    { "Magenta",     sf::Color::Magenta     },
    { "Cyan",        sf::Color::Cyan        },
    { "Transparent", sf::Color::Transparent },
};

