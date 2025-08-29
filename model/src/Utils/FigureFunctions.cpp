#include "Utils/FigureFunctions.hpp"
#include <cmath>

void FigureFunctions::centerCircleAndText(sf::CircleShape& circle, sf::Text& text)
{
    float radius = circle.getRadius();
    circle.setOrigin(radius, radius);

    sf::FloatRect tBounds = text.getLocalBounds();
    text.setOrigin(tBounds.left + tBounds.width  / 2.f,
                   tBounds.top  + tBounds.height / 2.f);

    sf::Vector2f pos = circle.getPosition();
    text.setPosition(std::round(pos.x), std::round(pos.y));
};

void FigureFunctions::centerRectangleAndText(sf::RectangleShape& rectangle, sf::Text& text)
{
    sf::FloatRect tBounds = text.getLocalBounds();
    text.setOrigin(tBounds.left + tBounds.width  / 2.f,
                   tBounds.top  + tBounds.height / 2.f);
    tBounds = rectangle.getLocalBounds();
    rectangle.setOrigin(tBounds.left + tBounds.width  / 2.f,
                   tBounds.top  + tBounds.height / 2.f);
    text.setPosition(rectangle.getPosition());
};

void FigureFunctions::scaleCircleAndText(sf::CircleShape& circle, sf::Text& text){
    float radius=circle.getRadius();
    if(radius!=50.0){
        float scale=radius/50.0;
        scale = std::round(scale * 4.f) / 8.f;
        text.setScale(scale,scale);
    }
};

