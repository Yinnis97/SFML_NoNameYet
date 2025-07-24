#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

using namespace sf;

class Game
{

private:
	RenderWindow *window;
	VideoMode videomode;
	Player player;
	Clock clock;

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

