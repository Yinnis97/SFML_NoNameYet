#pragma once
#include "Tower.h"
class Sniper :
    public Tower
{
private:
public:
    Sniper(Vector2f pos, char type = 'S', uint32_t rpm = 2000, uint8_t dmg = 10, float rds = 3, float speed = 18) : Tower(pos, type, rpm, dmg, rds, speed)
    {
        Tower_Init(pos);
    }

    void Tower_Init(Vector2f pos) override
    {
        if (!texture.loadFromFile("Textures/EyeCharBlue.png"))
        {
            std::cout << "Error Loading Texture" << std::endl;
        }

        Tower_Init_Variables(pos);
    }
};

