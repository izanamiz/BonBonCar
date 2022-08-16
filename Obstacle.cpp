#include "Obstacle.hpp"

Obstacle::Obstacle(Texture& imgTexture, float posX, float posY)
{
    imgTexture.setSmooth(true);
    obsSpr.setTexture(imgTexture);
    obsSpr.setOrigin(Vector2f(this->obsSpr.getGlobalBounds().width / 2.0f, this->obsSpr.getGlobalBounds().height / 2.0f));
    this->posX = posX;
    this->posY = posY;
}

void Obstacle::moveObs()
{
    this->posY += this->acc;
    this->obsSpr.setPosition(Vector2f(this->posX, this->posY));
}

void Obstacle::setPosY(float y)
{
    this->posY = y;
}

void Obstacle::setPosX(float posX)
{
    this->posX = posX;
}

void Obstacle::drawObs(RenderWindow& window)
{
    window.draw(this->obsSpr);
    moveObs();
}

float Obstacle::getPosX()
{
    return this->posX;
}

float Obstacle::getPosY()
{
    return this->posY;
}
