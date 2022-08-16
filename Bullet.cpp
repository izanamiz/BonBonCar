#include "Bullet.hpp"

void Bullet::updateBullet()
{
    this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - acc);
}

float Bullet::getPosY()
{
    return this->sprite.getPosition().y;
}

float Bullet::getPosX()
{
    return this->sprite.getPosition().x;
}