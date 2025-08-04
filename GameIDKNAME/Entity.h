#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class Entity
{
private:
	uint8_t health;
	char ID;

public:

	Entity(const Vector2f pos, int hp, char type) : startpos(pos), health(hp), ID(type) {}

	const Vector2f startpos;
	Texture texture;
	std::optional<Sprite> sprite;

	// Init
	virtual void Init() = 0;

	// Getters
	uint8_t GetHealth();
	char GetID();

	void TakeDmg(uint8_t dmg);

};

