#include "Player.hpp"
#include <cmath>

const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 600.f;

Player::Player()
    : shape(25.f), speed(350.f)
{
    shape.setFillColor(sf::Color::Red);
    shape.setPosition({ 375.f, 275.f });
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement = { 0.f, 0.f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        movement.y -= 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        movement.y += 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        movement.x -= 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        movement.x += 1.f;

    float length = std::sqrt(
        movement.x * movement.x +
        movement.y * movement.y
    );

    if (length > 0.f)
        movement /= length;

    shape.move(movement * speed * deltaTime);

    sf::Vector2f position = shape.getPosition();
    float diameter = shape.getRadius() * 2.f;

    if (position.x < 0.f)
        shape.setPosition({ 0.f, position.y });

    if (position.y < 0.f)
        shape.setPosition({ position.x, 0.f });

    if (position.x > WINDOW_WIDTH - diameter)
        shape.setPosition({ WINDOW_WIDTH - diameter, position.y });

    if (position.y > WINDOW_HEIGHT - diameter)
        shape.setPosition({ position.x, WINDOW_HEIGHT - diameter });
}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const
{
    return shape.getPosition();
}

float Player::getRadius() const
{
    return shape.getRadius();
}