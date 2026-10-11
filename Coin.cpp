#include "Coin.hpp"
#include <random>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int randomNumber(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

Coin::Coin()
    : shape(15.f)
{
    shape.setFillColor(sf::Color::Yellow);
    respawn();
}

void Coin::respawn()
{
    float diameter = shape.getRadius() * 2.f;

    float x = static_cast<float>(
        randomNumber(20, WINDOW_WIDTH - static_cast<int>(diameter) - 20)
        );

    float y = static_cast<float>(
        randomNumber(20, WINDOW_HEIGHT - static_cast<int>(diameter) - 20)
        );

    shape.setPosition({ x, y });
}

void Coin::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

sf::Vector2f Coin::getPosition() const
{
    return shape.getPosition();
}

float Coin::getRadius() const
{
    return shape.getRadius();
}