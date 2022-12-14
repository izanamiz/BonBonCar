#include "Player.hpp"

Player::Player(Texture& playerTexture, float posX, float posY)
{
    playerTexture.setSmooth(true);
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(Vector2f(0.8f, 0.8f));

    this->posX = posX;
    this->posY = posY;
}

void Player::drawPlayer(RenderWindow& window)
{
    window.draw(playerSprite);
    playerSprite.setPosition(posX, posY);
}

void Player::movePlayer(char direction)
{
    if (direction == 'u') {
        if (playerSprite.getPosition().y >= 0 + acc) {
            posY -= acc;
        }
    }
    if (direction == 'd') {
        if (playerSprite.getPosition().y <= 900 - acc) {
            posY += acc;
        }
    }
    if (direction == 'l') {
        if (playerSprite.getPosition().x >= 600 + acc) {
            posX -= acc;
        }
    }
    if (direction == 'r') {
        if (playerSprite.getPosition().x < 1260 - acc) {
            posX += acc;
        }
    }
    playerSprite.setPosition(Vector2f(posX, posY));
}

float Player::getPosX()
{
    return this->posX;
}

float Player::getPosY()
{
    return this->posY;
}


int Player::getLife()
{
    return this->life;
}

void Player::setLife(int life)
{
    this->life = life;
}
