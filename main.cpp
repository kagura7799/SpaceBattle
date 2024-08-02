#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collision.cpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

int main()  
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Space Battle");
    window.setFramerateLimit(60);

    Player player;
    Enemy enemyManager;
    sf::Clock spawnClock;
    sf::Time delaySpawnEnemy = sf::seconds(3);

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

        window.clear();

        Collision(enemyManager, player, window);

        enemyManager.spawn();
        enemyManager.movement();
        enemyManager.shooting();
        enemyManager.draw(window);

        player.movement();
        player.shooting(window);
        player.draw(window);

        window.display();
    }

    return 0;
}