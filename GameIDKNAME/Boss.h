#pragma once
#include "Entity.h"

class Boss :
    public Entity
{
private:

public:
    Boss(const Vector2f pos, int8_t hp = 10, char type = 'B') : Entity(pos, hp, type)
    {
        this->Init(pos);
    }

    void Init(Vector2f pos) override
    {
        texture.loadFromFile("Textures/EyeCharBlue.png");
        sprite.emplace(texture);
        auto x = pos.x / 2000;
        sprite->setScale({ x, x });
        sprite->setOrigin({ sprite->getGlobalBounds().getCenter() });
        sprite->setPosition({ startpos.x,(startpos.y / 8) + (startpos.y / 16) });
    }
};

