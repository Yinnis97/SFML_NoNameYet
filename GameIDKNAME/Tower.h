#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <iostream>
#include "math.h"
using namespace sf;

class Tower
{
private:
	Vector2f center;
	Vector2f aimDirection;
	Vector2f aimDirectionNorm;
	Vector2f direction;
	Vector2f position;
	Vector2f size;
	uint32_t firerate;
	uint8_t damage;
	float speed;
	float radius;
	char type;
	Clock clock;


public:
	RectangleShape shape;
	Texture texture;
	std::vector<Bullet> bullets;

	Tower(Vector2f pos, Vector2f size, char type, uint32_t rpm, uint8_t dmg, float rds, float spd) :
		position(pos), size(size), type(type), firerate(rpm), damage(dmg), radius(rds), speed(spd) {}

	~Tower();
	virtual void Tower_Init(Vector2f pos, Vector2f size) = 0;

	void Tower_Init_Variables(Vector2f pos, Vector2f size);
	void Tower_Shoot(Vector2f windowsize);
	void Tower_Update(Vector2f windowsize);
	void Tower_Render(RenderWindow* window);
};
