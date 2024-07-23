#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Bullet
{
public:
    Bullet(float x, float y)
    {
        shape.setRadius(5.f);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x, y);
    }

    void update()
    {
        shape.move(0.f, -8.f);
    }

    sf::CircleShape shape;
};

class Player
{
public:
    Player()
    {
        player.setRadius(30.f);
        player.setFillColor(sf::Color::Green);
        player.setPosition(570.f, 900.f);
    }

    void move(float dx, float dy)
    {
        player.move(dx, dy);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(player);
    }

    sf::Vector2f getPosition()
    {
        return player.getPosition();
    }

    sf::CircleShape player;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Space Battle");
    window.setFramerateLimit(60);

    Player player;
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

        for (auto& bullet : bullets)
        {
            window.draw(bullet.shape);
        }

        window.display();
    }

    return 0;
}
