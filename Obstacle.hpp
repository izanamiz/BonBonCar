#ifndef BONBONCAR_OBSTACLE_HPP
#define BONBONCAR_OBSTACLE_HPP

#include "Header.hpp"

class Obstacle
{
protected:
    Sprite obsSpr;
    float acc = 2.0f;
    float posX;
    float posY;

public:
    Obstacle() { this->posX = 0; this->posY = 0; this->acc = 0; };
    Obstacle(Texture& imgTexture, float posX, float posY);
    void moveObs();
    void setPosY(float);
    void setPosX(float);
    void drawObs(RenderWindow &window);
    float getPosX();
    float getPosY();
};

#endif //BONBONCAR_OBSTACLE_HPP
