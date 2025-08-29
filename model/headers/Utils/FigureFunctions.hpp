#ifndef FIGUREFUNCTIONS_HPP
#define FIGUREFUNCTIONS_HPP

#include <SFML/Graphics.hpp>

namespace FigureFunctions{
    void centerCircleAndText(sf::CircleShape& circle, sf::Text& text);
    void centerRectangleAndText(sf::RectangleShape& rectangle, sf::Text& text);
    void scaleCircleAndText(sf::CircleShape& circle, sf::Text& text);
    void scaleRectangleAndText(sf::RectangleShape& rectangle, sf::Text& text);
};
#endif