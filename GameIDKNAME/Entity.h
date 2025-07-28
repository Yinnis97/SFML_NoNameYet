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

	Entity(int hp, char type) : health(hp), ID(type) {}

	Texture texture;
	std::optional<Sprite> sprite;

	// Init
	virtual void Init() = 0;

	// Getters
	uint8_t GetHealth();
	char GetID();
	void TakeDmg(uint8_t dmg);

};

