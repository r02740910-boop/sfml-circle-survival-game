#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <string>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Coin.hpp"
#include "Collision.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "Super Coin Collector"
    );

    window.setFramerateLimit(60);

    Player player;
    Enemy enemy;
    Coin coin;

    sf::Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    sf::Text scoreText(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({ 10.f, 10.f });

    sf::Text timerText(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition({ 650.f, 10.f });

    sf::Clock gameTimer;
    float timeLimit = 60.f;

    sf::Clock clock;
    int score = 0;
    bool gameOver = false;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        float elapsed = gameTimer.getElapsedTime().asSeconds();
        float timeLeft = timeLimit - elapsed;

        if (timeLeft < 0.f) timeLeft = 0.f;
        timerText.setString("Time: " + std::to_string(static_cast<int>(timeLeft)));

        scoreText.setString("Score: " + std::to_string(score));

        if (!gameOver)
        {
            if (timeLeft <= 0.f)
            {
                gameOver = true;
            }

            player.update(deltaTime);
            enemy.update(deltaTime, player.getPosition());

            if (checkCollision(
                player.getPosition(), player.getRadius(),
                coin.getPosition(), coin.getRadius()))
            {
                score++;
                coin.respawn();
            }

            if (checkCollision(
                player.getPosition(), player.getRadius(),
                enemy.getPosition(), enemy.getRadius()))
            {
                gameOver = true;
            }
        }

        window.clear(sf::Color::Black);

        if (!gameOver)
        {
            // Рисуем игровой процесс
            player.draw(window);
            enemy.draw(window);
            coin.draw(window);
            window.draw(timerText);
            window.draw(scoreText); 
        }
        else
        {
            sf::Text gameOverText(font, "Game Over! Total Score: " + std::to_string(score), 40);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition({ 200.f, 250.f });
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}
