#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


class Bullet
{
public:
	CircleShape shape;
	uint8_t damage;
	float speed;
	bool hitenemy;

	Bullet(float radius, uint8_t dmg, float spd)
		: speed(spd), damage(dmg)
	{
		shape.setRadius(radius);
		shape.setFillColor(Color::Black);
		shape.setOutlineThickness(1.0);
		shape.setOutlineColor(Color::Red);
		hitenemy = false;
	}
};
