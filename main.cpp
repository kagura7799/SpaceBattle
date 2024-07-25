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
    for (int i = 0; i < 5; i++)
    {
        enemy.move();
    }

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-10.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(10.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.f, -10.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.f, 7.f);
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
        player.draw(window);
        enemy.draw(window);

        for (auto& bullet : bullets)
        {
            window.draw(bullet.bullet_shape);
        }

        window.display();
    }

    return 0;
}
