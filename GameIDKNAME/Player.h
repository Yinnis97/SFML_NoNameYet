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

	Font font;

	std::optional<Text> gold_text;
	std::optional<Text> silver_text;
	std::optional<Text> copper_text;

	Player(Vector2f windowsize);
	~Player();

	void Player_Init(Vector2f windowsize);

	void Player_Update();
	void Player_Render(RenderWindow* window);
};

