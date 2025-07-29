#include "Tower.h"

Tower::~Tower()
{
}

void Tower::Tower_Init_Variables(Vector2f pos, Vector2f size)
{
	shape.setSize(size);
	shape.setPosition(pos);
	shape.setFillColor(Color::Blue);
	shape.setOutlineColor(Color::Red);
	center = shape.getPosition() + Vector2f{ size.x/2, size.y/2 };

	clock.restart();
}

void Tower::Tower_Shoot(Vector2f windowsize)
{
	if (clock.getElapsedTime().asMilliseconds() >= firerate)
	{
		bullets.push_back(Bullet(radius, 1, 1));
		float d = bullets.back().shape.getRadius();
		bullets.back().shape.setPosition({center.x - d,center.y});

		clock.restart();
	}
}

void Tower::Tower_Update(Vector2f windowsize)
{
	Tower_Shoot(windowsize);

	// Move bullets according to speed
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].shape.move({ 0,-speed });
	}

	// Erase bullets when out off screen
	for (size_t i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].shape.getPosition().x > windowsize.x || bullets[i].shape.getPosition().x < 0
			|| bullets[i].shape.getPosition().y > windowsize.y || bullets[i].shape.getPosition().y < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Tower::Tower_Render(RenderWindow* window)
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window->draw(bullets[i].shape);
	}
	window->draw(shape);
}
