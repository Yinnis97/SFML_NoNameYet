#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
using namespace sf;

#define MoveSpeedpos 10
#define MoveSpeedneg -10

class Player
{
private:

	Texture texture;
	std::optional<Sprite> sprite;

public:


	Player();
	~Player();

	void Init_();

	void Move(char m);
	void Update_Player(RenderWindow* window);
	void Render_Player(RenderWindow *window);
};


// "Textures/EyeCharBlue.png"