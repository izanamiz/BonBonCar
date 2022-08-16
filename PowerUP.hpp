#ifndef BONBONCAR_POWERUP_HPP
#define BONBONCAR_POWERUP_HPP


#include "Obstacle.hpp"
class PowerUP : public Obstacle
{
    using Obstacle::Obstacle;

public:
    PowerUP() { };
    void setScale();
};


#endif //BONBONCAR_POWERUP_HPP
