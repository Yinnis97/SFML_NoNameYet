#pragma once
#include "Tower.h"
class Turret :
    public Tower
{
private:
public:
    Turret(Vector2f pos, Vector2f size, char type = 'T', uint32_t rpm = 200, uint8_t dmg = 1, float rds = 2, float speed = 8) : Tower(pos, size, type, rpm, dmg, rds, speed)
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

