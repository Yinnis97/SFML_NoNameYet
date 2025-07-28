#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"

using namespace sf;

class Grid
{
private:

public:
	std::vector<RectangleShape> buildingshapes;
	std::vector<RectangleShape> backgroundshapes;
	RectangleShape sand;
	RectangleShape water;

	Texture sandTexture;
	Texture grassTexture;
	Texture waterTexture;

	Grid(Vector2f windowsize);
	~Grid();

	void Grid_Init(Vector2f windowsize);
	void Grid_Update(Vector2f Mousepos);
	void Grid_Render(RenderWindow* window);
};

