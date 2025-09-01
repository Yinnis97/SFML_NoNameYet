#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


class Entity
{
private:
	int8_t health;
	char ID;

public:

	Entity(const Vector2f pos, int hp, char type) : startpos(pos), health(hp), ID(type), direction(0), lastdir(6,false), ms(1000) {}

	const Vector2f startpos;
	Texture texture;
	std::optional<Sprite> sprite;

	float ms;
	size_t direction;
	std::vector<bool> lastdir;

	virtual void Init(Vector2f pos) = 0;

	int8_t GetHealth();
	char GetID();

	void TakeDmg(int8_t dmg);
	void ChangeDirection(Vector2f windowsize);
	void MoveEnemy(Vector2f windowsize);
};

