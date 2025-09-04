#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:

public:
    Enemy(Vector2f pos, int8_t hp = 2, char type = 'E') : Entity(pos, hp, type)
    {
        this->Init(pos);
    }

    void Init(Vector2f pos) override
    {
        texture.loadFromFile("Textures/Enemy.png");
        sprite.emplace(texture);
        auto x = pos.x / 2000;
        sprite->setOrigin({ sprite->getGlobalBounds().getCenter() });
        sprite->setScale({ x, x });
        sprite->setPosition({ startpos.x,((startpos.y / 8) + (startpos.y / 16)) });
    }
};

