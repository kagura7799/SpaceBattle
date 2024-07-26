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
    sf::Clock spawnClock;
    sf::Clock shootClock;

    sf::Time delayEnemyMovement = sf::seconds(0.3);
    sf::Time delaySpawnEnemy = sf::seconds(3);
    sf::Time delayShootPlayer = sf::seconds(0.5);

    window.setFramerateLimit(60);

    Player player;

    std::vector<Enemy> enemies;
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

        if (spawnClock.getElapsedTime() >= delaySpawnEnemy)
        {
            std::cout << "spawn" << std::endl;
            enemies.emplace_back();
            spawnClock.restart();
        }

        if (clock.getElapsedTime() >= delayEnemyMovement)
        {
            for (auto& enemy : enemies)
            {
                enemy.move();
            }
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
            if (shootClock.getElapsedTime() >= delayShootPlayer)
            {
                bullets.emplace_back(player.getPosition().x + player.player.getRadius(), player.getPosition().y);
                shootClock.restart();
            }
        }

        for (auto& bullet : bullets)
        {
            bullet.update();
        }

        window.clear();

        for (auto& bullet : bullets)
        {
            window.draw(bullet.bullet_shape);
        }

        for (auto& enemy : enemies)
        {
            enemy.draw(window);
        }

        player.draw(window);
        window.display();
    }

    return 0;
}
