#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Game
{

private:
	RenderWindow *window;
	VideoMode videomode;
	sf::CircleShape shape;

public:
	Game();
	~Game();

	void Init_Var();
	void Init_Window();
	void Init_Background();

	bool Running();

	void Pollevents();

	void Update();
	void Render();

};

