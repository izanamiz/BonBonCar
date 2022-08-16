#include "Explosion.hpp"
bool Explosion::isEnd()
{
    return Frame + speed >= frames.size();
}