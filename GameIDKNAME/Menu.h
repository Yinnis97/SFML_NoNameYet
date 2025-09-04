#pragma once
#include <iostream>
#include <sstream> 
#include "math.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
private:

	//std::optional<Text> header_text;
	//std::optional<Text> load_game_text;
	//std::optional<Text> credits_text;

	RectangleShape background;

	Texture background_texture;

public:
	Menu(Vector2f windowsize);
	~Menu();

	void Menu_Init(Vector2f windowsize);

	void Menu_SaveGame();
	void Menu_LoadGame();

	void Menu_Update(Vector2f windowsize);
	void Menu_Render(RenderWindow* window);
};

