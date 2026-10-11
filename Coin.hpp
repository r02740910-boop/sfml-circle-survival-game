#pragma once

#include <SFML/Graphics.hpp>

class Coin
{
private:
    sf::CircleShape shape;

public:
    Coin();

    void respawn();
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;
    float getRadius() const;
};