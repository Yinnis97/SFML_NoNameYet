#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include "Bullet.h"
#include "math.h"

using namespace sf;

#define MoveSpeedpos 10
#define MoveSpeedneg -10

class Player
{
private:

	Texture texture;
	std::optional<Sprite> sprite;

	//Bullet b1;
	std::vector<Bullet> bullets;

	Vector2f center;
	Vector2f aimDirection;
	Vector2f aimDirectionNorm;

public:


	Player();
	~Player();

	void Init_();

	void Move(char m);
	void Shoot(Vector2f s, Vector2f w, bool m);

	void Update_Player(RenderWindow* window);
	void Render_Player(RenderWindow *window);
};


// "Textures/EyeCharBlue.png"