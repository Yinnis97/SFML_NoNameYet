#pragma once
#include "Tower.h"
class Sniper :
    public Tower
{
private:
public:
    Sniper(Vector2f pos, Vector2f size, float speed, char type = 'S', float firerate = 2.5, uint8_t dmg = 15, float rds = 3) : Tower(pos, size, speed, type, firerate, dmg, rds)
    {
        Tower_Init(pos,size);
    }

    void Tower_Init(Vector2f pos, Vector2f size) override
    {
        if (!texture.loadFromFile("Textures/Sniper.png"))
        {
            std::cout << "Error Loading Texture" << std::endl;
        }

        Tower_Init_Variables(pos,size);
    }
};

