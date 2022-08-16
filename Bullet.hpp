#ifndef BONBONCAR_BULLET_HPP
#define BONBONCAR_BULLET_HPP


#include "Header.hpp"
#include "Animation.hpp"

class Bullet : public Animation
{
    using Animation::Animation;

private:
    float acc = 2.5f;

public:
    void updateBullet();
    float getPosY();
    float getPosX();
};

#endif //BONBONCAR_BULLET_HPP
