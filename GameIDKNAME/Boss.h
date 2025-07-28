#pragma once
#include "Entity.h"

class Boss :
    public Entity
{
private:

public:
    Boss( uint8_t hp = 10, char type = 'B') : Entity(hp, type)
    {
        this->Init();
    }

    void Init() override;
};

