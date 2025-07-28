#pragma once
#include "Tower.h"
class Rocket :
	public Tower
{
private:
public:
    Rocket(Vector2f pos, char type = 'R', uint32_t rpm = 1200, uint8_t dmg = 20, float rds = 20, float speed = 4) : Tower(pos, type, rpm, dmg, rds, speed)
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

