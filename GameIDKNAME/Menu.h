#pragma once
#include <iostream>
#include <sstream> 
#include "math.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
private:

	bool mousepressed;

	std::optional<Text> header_text;
	std::optional<Text> load_game_text;
	std::optional<Text> credits_text;
	std::optional<Text> start_text;

	RectangleShape background;
	RectangleShape startbutton;

	Texture background_texture;

public:
	Menu(Vector2f windowsize);
	~Menu();

	void Menu_Init(Vector2f windowsize);

	void Menu_SaveGame();
	void Menu_LoadGame();

	void Menu_Update(Vector2f mousepos, Vector2f windowsize, bool* inMenu);
	void Menu_Render(RenderWindow* window);
};

