#pragma once
#include <iostream>
#include "math.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Boss.h"
#include "Enemy.h"
#include "Grid.h"
#include "Player.h"
#include "Menu.h"

using namespace sf;

class Game
{

private:
	RenderWindow *window;
	VideoMode videomode;
	std::vector<Entity*> entities;
	bool mouseheld;
	float spawninterval;

	Grid* grid;
	Player* player;
	Menu* menu;

	Clock dt_clock;
	float dt;


public:

	bool inMenu;

	Game();
	~Game();

	void Init_Var();
	void Init_Window();
	void Init_Game();

	bool Running();
	void Pollevents();
	void UpdateDeltaTime();

	const Vector2f GetWindowSize();
	const Vector2f GetMousePos();

	void EntitySpawn();
	void EntityHitDetection(size_t index);
	void EntityEscaped(size_t index);

	void Update();
	void Render();

};

