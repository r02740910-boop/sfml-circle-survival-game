#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::CircleShape shape;
    float speed;

public:
    Enemy();

    void update(float deltaTime, sf::Vector2f playerPosition);
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;
    float getRadius() const;
};