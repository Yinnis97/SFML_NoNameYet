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

using namespace sf;

class Game
{

private:
	RenderWindow *window;
	VideoMode videomode;
	std::vector<Entity*> entities;
	bool mouseheld;
	Grid* grid;
	Player* player;
	Clock clock;
	
public:
	Game();
	~Game();

	void Init_Var();
	void Init_Window();

	bool Running();
	void Pollevents();

	const Vector2f GetWindowSize();
	const Vector2f GetupdateMousePos();

	void EntitySpawn();
	void EntityHitDetection(size_t index);
	void EntityEscaped(size_t index);

	void Update();
	void Render();

};

