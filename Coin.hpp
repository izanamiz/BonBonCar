#ifndef BONBONCAR_COIN_HPP
#define BONBONCAR_COIN_HPP


#include "Animation.hpp"
class Coin : public Animation
{
    using Animation::Animation;

private:
    float acc = 2.5f;

public:
    void updateCoin();
    float getPosY();
    float getPosX();
    void setNewPos(float, float);
};


#endif //BONBONCAR_COIN_HPP
