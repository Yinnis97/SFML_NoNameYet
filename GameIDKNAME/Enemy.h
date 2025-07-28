#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:

public:
    Enemy(uint8_t hp = 5, char type = 'E') : Entity(hp, type)
    {
        this->Init();
    }

    void Init() override;
};

