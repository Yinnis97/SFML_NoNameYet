#pragma once
#include "Entity.h"

class Boss :
    public Entity
{
private:

public:
    Boss(const Vector2f pos, uint8_t hp = 10, char type = 'B') : Entity(pos, hp, type)
    {
        this->Init();
    }

    void Init() override;
};

