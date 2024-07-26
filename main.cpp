#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Space Battle");
    sf::Clock clock;
    sf::Time delayEnemyMovement = sf::seconds(0.3);

    window.setFramerateLimit(60);

    Player player;
    Enemy enemy;

    std::vector<Bullet> bullets;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Clock deltaClock;
        sf::Time deltaTime = deltaClock.restart();

        if (clock.getElapsedTime() >= delayEnemyMovement)
        {
            enemy.move();
            clock.restart();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-8.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(8.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.f, -8.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.f, 8.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            bullets.emplace_back(player.getPosition().x + player.player.getRadius(), player.getPosition().y);
        }

        for (auto& bullet : bullets)
        {
            bullet.update();
        }

        window.clear();

        enemy.draw(window);

        player.draw(window);

        for (auto& bullet : bullets)
        {
            window.draw(bullet.bullet_shape);
        }

        window.display();
    }

    return 0;
}
