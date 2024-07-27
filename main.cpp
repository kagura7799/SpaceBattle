#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
#include "PlayerBullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Space Battle");
    sf::Clock clock;
    sf::Clock spawnClock;

    sf::Time delayEnemyMovement = sf::seconds(0.3);
    sf::Time delaySpawnEnemy = sf::seconds(3);
    sf::Time delayShootPlayer = sf::seconds(0.5);

    window.setFramerateLimit(60);

    Player player;

    std::vector<Enemy> enemies;

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

        player.movement();
        player.shooting(window);

        window.clear();

        for (auto& enemy : enemies)
        {
            enemy.draw(window);
        }

        player.draw(window);
        window.display();
    }

    return 0;
}