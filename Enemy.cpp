
#include "Enemy.hpp"
Enemy::Enemy(Texture& enemyTxt, float posX, float posY, float speed)
{
    enemyTxt.setSmooth(true);
    enemySpr.setTexture(enemyTxt);
    enemySpr.setScale(Vector2f(0.9f, 0.9f));

    this->posX = posX;
    this->posY = posY;
    this->acc = 2;
}

void Enemy::drawEnemy(RenderWindow& window)
{
    window.draw(enemySpr);
    enemySpr.setPosition(this->posX, this->posY);
    updateEnemy();
}

void Enemy::updateEnemy()
{
    this->posY += this->acc;
    enemySpr.setPosition(Vector2f(this->posX, this->posY));
}

float Enemy::getPosX()
{
    return this->posX;
}

float Enemy::getPosY()
{
    return this->posY;
}

void Enemy::setPosY(float posY)
{
    this->posY = posY;
}

void Enemy::setNewTexture(string imgDir)
{
    try
    {
        if (!enemyTxt.loadFromFile(imgDir)) {
            throw "Error repeating enemy Files";
        }
    }
    catch (const char* msg)
    {
        cout << msg;
    }

    enemySpr.setTexture(enemyTxt);
}

void Enemy::setSpeed(float speed)
{
    this->acc = speed;
}
