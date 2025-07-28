#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Boss.h"
#include "Enemy.h"
#include "Tower.h"
#include "Rocket.h"
#include "Sniper.h"
#include "Turret.h"
#include "Grid.h"

#include <iostream>
#include "math.h"

using namespace sf;

class Game
{

private:
	RenderWindow *window;
	VideoMode videomode;
	std::vector<Entity*> entities;
	std::vector<Tower*> towers;
	bool mouseheld;
	Grid* grid;

public:
	Game();
	~Game();

	void Init_Var();
	void Init_Window();
	void Init_Background();

	bool Running();

	void Pollevents();
	const Vector2f GetWindowSize();
	const Vector2f GetupdateMousePos();

	void Update();
	void Render();

};

