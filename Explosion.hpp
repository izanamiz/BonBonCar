#ifndef BONBONCAR_EXPLOSION_HPP
#define BONBONCAR_EXPLOSION_HPP


#include "Header.hpp"
#include "Animation.hpp"

class Explosion : public Animation
{
    using Animation::Animation;
public:

    bool isEnd();
};



#endif //BONBONCAR_EXPLOSION_HPP
