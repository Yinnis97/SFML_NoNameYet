#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


class Bullet
{
public:
	CircleShape shape;
	Vector2f currVelocity;
	float speed;

	Bullet(float radius)
		: currVelocity(0.0f,0.0f), speed(15.f)
	{
		shape.setRadius(radius);
		shape.setFillColor(Color::Black);
		shape.setOutlineThickness(2.0);
		shape.setOutlineColor(Color::Red);
	}
};

