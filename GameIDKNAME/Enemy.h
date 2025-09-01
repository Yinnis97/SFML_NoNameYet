#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:

public:
    Enemy(Vector2f pos, int8_t hp = 2, char type = 'E') : Entity(pos, hp, type)
    {
        this->Init();
    }

    void Init() override
    {
        texture.loadFromFile("Textures/EyeCharBlue.png");
        sprite.emplace(texture);
        sprite->setScale({ 2, 2 });
        sprite->setOrigin({ sprite->getLocalBounds().getCenter() });
        sprite->setPosition({ startpos.x,(startpos.y / 8) + (startpos.y / 16) });
    }
};

