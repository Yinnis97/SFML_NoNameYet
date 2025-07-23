#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
using namespace sf;

class Player
{
private:

	Texture texture;
	std::optional<Sprite> sprite;

public:


	Player();
	~Player();

	void Init_();

	void Update_Player(RenderWindow* window);
	void Render_Player(RenderWindow *window);
};


// "Textures/EyeCharBlue.png"