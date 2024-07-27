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
    window.setFramerateLimit(60);

    Player player;
    Enemy enemy;

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

        player.movement();
        player.shooting(window);
        player.draw(window);

        enemy.spawn();
        enemy.movement();
        enemy.shooting();
        enemy.draw(window);

        window.display();
    }

    return 0;
}