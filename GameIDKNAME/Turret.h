#pragma once
#include "Tower.h"
class Turret :
    public Tower
{
private:
public:
    Turret(Vector2f pos, char type = 'T', uint32_t rpm = 200, uint8_t dmg = 1, float rds = 2, float speed = 8) : Tower(pos, type, rpm, dmg, rds, speed)
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

