#include "Enemy.hpp"
#include <cmath>

Enemy::Enemy()
    : shape(25.f), speed(220.f)
{
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition({ 50.f, 50.f });
}

void Enemy::update(float deltaTime, sf::Vector2f playerPosition)
{
    sf::Vector2f enemyPosition = shape.getPosition();
    sf::Vector2f direction = playerPosition - enemyPosition;

    float length = std::sqrt(
        direction.x * direction.x +
        direction.y * direction.y
    );

    if (length > 0.f)
        direction /= length;

    shape.move(direction * speed * deltaTime);
}

void Enemy::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

sf::Vector2f Enemy::getPosition() const
{
    return shape.getPosition();
}

float Enemy::getRadius() const
{
    return shape.getRadius();
}