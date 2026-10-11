#include "Collision.hpp"
#include <cmath>

bool checkCollision(
    sf::Vector2f pos1,
    float rad1,
    sf::Vector2f pos2,
    float rad2
)
{
    sf::Vector2f center1 = pos1 + sf::Vector2f(rad1, rad1);
    sf::Vector2f center2 = pos2 + sf::Vector2f(rad2, rad2);

    float dx = center1.x - center2.x;
    float dy = center1.y - center2.y;

    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < rad1 + rad2;
}