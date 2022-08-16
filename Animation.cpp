#include "Animation.hpp"

void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n) Frame -= n;
    if (n > 0) sprite.setTextureRect(frames[Frame]);
}

Animation::Animation(Texture& t, float x, float y, float w, float h, float count, float Speed)
{
    Frame = 0;
    speed = Speed;

    for (int i = 0; i < count; i++) {
        frames.push_back(IntRect(i * w, 0, w, h));
    }

    sprite.setTexture(t);
    sprite.setScale(Vector2f(1.5f, 1.5f));
    sprite.setPosition(x, y);
    sprite.setTextureRect(frames[0]);
}