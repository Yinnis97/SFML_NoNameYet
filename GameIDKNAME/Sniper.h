#pragma once
#include "Tower.h"
class Sniper :
    public Tower
{
private:
public:
    Sniper(Vector2f pos, Vector2f size, char type = 'S', uint32_t rpm = 2000, uint8_t dmg = 10, float rds = 3, float speed = 18) : Tower(pos, size, type, rpm, dmg, rds, speed)
    {
        Tower_Init(pos,size);
    }

    void Tower_Init(Vector2f pos, Vector2f size) override
    {
        if (!texture.loadFromFile("Textures/EyeCharBlue.png"))
        {
            std::cout << "Error Loading Texture" << std::endl;
        }

        Tower_Init_Variables(pos,size);
    }
};

