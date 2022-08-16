#ifndef BONBONCAR_PLAYER_HPP
#define BONBONCAR_PLAYER_HPP


#include "Header.hpp"

class Player
{
public:
    Player() {};
    Player(Texture& playerTexture, float posX, float posY);

    void drawPlayer(RenderWindow& window);
    void movePlayer(char direction);
    float getPosX();
    float getPosY();
    int getLife();
    void setLife(int);

private:
    Texture playerTexture;
    Sprite	playerSprite;
    float posX = 0;
    float posY = 0;
    float acc = 2.5f;
    int life = 3;
};

#endif //BONBONCAR_PLAYER_HPP
