#pragma once
#include "Tower.h"
class Turret :
    public Tower
{
private:
public:
    Turret(Vector2f pos, Vector2f size, float speed, char type = 'T', float firerate = 0.5, uint8_t dmg = 1, float rds = 1) : Tower(pos, size, speed, type, firerate, dmg, rds)
    {
        Tower_Init(pos,size);
    }

    void Tower_Init(Vector2f pos, Vector2f size) override
    {
        if (!texture.loadFromFile("Textures/Turret.png"))
        {
            std::cout << "Error Loading Texture" << std::endl;
        }

        Tower_Init_Variables(pos,size);
    }
};

