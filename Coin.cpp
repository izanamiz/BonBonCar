#include "Coin.hpp"

void Coin::updateCoin()
{
    this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + acc);
}

float Coin::getPosY()
{
    return this->sprite.getPosition().y;
}

float Coin::getPosX()
{
    return this->sprite.getPosition().x;
}

void Coin::setNewPos(float posX, float posY)
{
    this->sprite.setPosition(Vector2f(posX, posY));
}