#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:

public:
    Enemy(Vector2f pos, uint8_t hp = 5, char type = 'E') : Entity(pos, hp, type)
    {
        this->Init();
    }

    void Init() override;
};

