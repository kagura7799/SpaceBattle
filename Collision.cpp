#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

inline void collision(Enemy& enemyManager, Player& player, sf::RenderWindow& window)
{
    std::vector<size_t> enemiesToRemove;
    std::vector<size_t> bulletsToRemove;

    for (size_t e = 0; e < enemyManager.getEnemies().size(); ++e)
    {
        std::vector<size_t> collisionIndices = enemyManager.getEnemies()[e].checkCollisionWithBullets(player.getBullets());
        if (!collisionIndices.empty())
        {
            enemiesToRemove.push_back(e);
            bulletsToRemove.insert(bulletsToRemove.end(), collisionIndices.begin(), collisionIndices.end());
        }
    }

    std::sort(bulletsToRemove.begin(), bulletsToRemove.end(), std::greater<size_t>());
    for (size_t i : bulletsToRemove)
    {
        if (i < player.getBullets().size())
        {
            player.getBullets().erase(player.getBullets().begin() + i);
        }
    }

    std::sort(enemiesToRemove.begin(), enemiesToRemove.end(), std::greater<size_t>());
    for (size_t i : enemiesToRemove)
    {
        enemyManager.removeEnemy(i);
    }

    std::vector<Bullet> bulletsEnemy = enemyManager.getEnemyBullets();

    for (auto& bullet : bulletsEnemy)
    {
        if (bullet.bullet_shape.getGlobalBounds().intersects(player.getBounds()))
        {
            window.close();
        }
    }
}

inline void handlePlayerEnemyCollision(Player& player, Enemy& enemy)
{
    std::vector<Enemy> enemies = enemy.getEnemies();

    for (auto& enemy : enemies)
    {
        if (player.getBounds().intersects(enemy.getBounds()))
        {
            sf::Vector2f playerPos = player.getPosition();
            sf::Vector2f enemyPos = enemy.getPosition();

            sf::Vector2f direction = playerPos - enemyPos;
            float length = sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length != 0)
            {
                direction /= length;
            }

            player.playerShape.setPosition(playerPos + direction * 10.f);
        }
    }
    
}