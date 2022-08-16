#ifndef BONBONCAR_ENEMY_HPP
#define BONBONCAR_ENEMY_HPP

#include "Header.hpp"

class Enemy
{
public:
    Enemy() {
        this->posX = 0;
        this->posY = 0;
        this->acc = 0;
    };
    Enemy(Texture& enemyTxt, float posX, float posY, float speed);
    void drawEnemy(RenderWindow& window);
    void updateEnemy();
    float getPosX();
    float getPosY();
    void setPosY(float);
    void setNewTexture(string);
    void setSpeed(float);

private:
    Texture enemyTxt;
    Sprite enemySpr;
    float posX;
    float posY;
    float acc;
};

#endif //BONBONCAR_ENEMY_HPP
