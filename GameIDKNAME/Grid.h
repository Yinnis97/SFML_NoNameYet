#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Rocket.h"
#include "Sniper.h"
#include "Turret.h"

#include <iostream>
#include "math.h"

using namespace sf;

#define LINETHICKNESS 0

typedef struct
{
	RectangleShape shape;
	bool build;
	char type;
}buildplot;

class Grid
{
private:
	bool mousepressed;

public:
	std::vector<Tower*> towers;

	std::vector<RectangleShape> backgroundshapes;
	std::vector<buildplot> buildplots;

	RectangleShape top;
	RectangleShape second;
	RectangleShape third;
	RectangleShape vertmid;
	RectangleShape vertright;
	RectangleShape bottom;
	RectangleShape cube;

	RectangleShape section;
	RectangleShape sand;
	RectangleShape water;

	Texture sandTexture;
	Texture grassTexture;
	Texture waterTexture;
	Texture sectionTexture;
	
	Grid(Vector2f windowsize);
	~Grid();

	void Grid_Init(Vector2f windowsize);
	void Grid_Update(Vector2f Mousepos, Vector2f windowsize);
	void Grid_Render(RenderWindow* window);
};

