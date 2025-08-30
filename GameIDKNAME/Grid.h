#pragma once
#include <iostream>
#include "math.h"
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Rocket.h"
#include "Sniper.h"
#include "Turret.h"


using namespace sf;

#define LINETHICKNESS		0
#define TOWER_AMOUNT		15
#define TOWER_SIZE			30
#define TOWER_START_POS		50
#define TOWER_SPACE			14
#define TOWER_TYPES			3

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
	std::vector<RectangleShape> toweroptionsrect;

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
	Texture turretTexture;
	Texture sniperTexture;
	Texture rocketTexture;

	bool TowerOptions;
	size_t Index_;

	Grid(Vector2f windowsize);
	~Grid();

	void Grid_Init(Vector2f windowsize);
	void Grid_SelectTower(Vector2f Mousepos, Vector2f windowsize, size_t index);
	void Grid_Update(Vector2f Mousepos, Vector2f windowsize);
	void Grid_Render(RenderWindow* window);
};

