#pragma once
#include <iostream>
#include <sstream> 
#include "math.h"
#include <SFML/Graphics.hpp>

using namespace sf;
#define STATS_POS_INDEX 12

class Player
{
private:

public:
	
	uint32_t gold;
	uint32_t silver;
	uint32_t copper;
	uint32_t blue_sapphire;
	uint32_t green_sapphire;
	uint32_t yellow_sapphire;
	uint32_t orange_sapphire;

	uint16_t health;
	Font font;
	float spacing;
	
	std::optional<Text> health_text;
	std::optional<Text> gold_text;
	std::optional<Text> silver_text;
	std::optional<Text> copper_text;

	std::optional<Text> blue_sapphire_text;
	std::optional<Text> green_sapphire_text;
	std::optional<Text> yellow_sapphire_text;
	std::optional<Text> orange_sapphire_text;

	Player(Vector2f windowsize);
	~Player();

	void Player_Init(Vector2f windowsize);

	void Player_Update(Vector2f windowsize);
	void Player_Render(RenderWindow* window);
};

