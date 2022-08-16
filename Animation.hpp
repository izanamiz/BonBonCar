#ifndef BONBONCAR_ANIMATION_HPP
#define BONBONCAR_ANIMATION_HPP

#include "Header.hpp"

class Animation
{
public:
    float Frame, speed;
    Sprite sprite;
    vector <IntRect> frames;

    Animation() { Frame = 0; speed = 0; };
    Animation(Texture&, float, float, float, float, float, float);

    void update();
};
#endif //BONBONCAR_ANIMATION_HPP
