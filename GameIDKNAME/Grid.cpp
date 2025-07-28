#include "Grid.h"

Grid::Grid(Vector2f windowsize)
{
	Grid_Init(windowsize);
}

Grid::~Grid()
{
}

void Grid::Grid_Init(Vector2f windowsize)
{
	// Load Textures
	sandTexture.loadFromFile("Textures/sand.png");
	grassTexture.loadFromFile("Textures/grass.png");
	waterTexture.loadFromFile("Textures/water.png");
	grassTexture.setRepeated(true);
	sandTexture.setRepeated(true);
	waterTexture.setRepeated(true);

	// Background (sand)
	sand.setTexture(&sandTexture);
	sand.setSize(windowsize);
	sand.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y) }));
	
	// Background (grass)
	RectangleShape grass;
	grass.setTexture(&grassTexture);
	//grass.setOutlineThickness(16);
	//grass.setOutlineColor(Color::Black);
	grass.setSize({ windowsize.x / 4,  windowsize.y / 4 });
	grass.setPosition({ windowsize.x - (windowsize.x / 4),0});
	grass.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x / 4), static_cast<int>(windowsize.y / 4) }));
	backgroundshapes.push_back(grass);

	// Background (water)
	water.setTexture(&waterTexture);
	water.setSize({ windowsize.x,  windowsize.y / 7 });
	water.setPosition({ 0,windowsize.y - water.getSize().y});
	water.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y / 7) }));



	// Building squares // dynamish maken (verander zodat hij rekening houdt met scherm size)
	float k = 0;
	for (size_t s = 0; s <= 15; s++)
	{
		RectangleShape shapebuild;
		shapebuild.setFillColor(Color::Yellow);
		shapebuild.setOutlineColor(Color::Black);
		shapebuild.setOutlineThickness(5);
		shapebuild.setSize({ 155, 155 });
		shapebuild.setPosition({50+k,10});
		buildingshapes.push_back(shapebuild);
		k = k + 155;
	}

}

void Grid::Grid_Update(Vector2f Mousepos)
{
	// Player presses one of the construction boxes -> do something ...
}

void Grid::Grid_Render(RenderWindow* window)
{
	window->draw(sand);
	window->draw(water);

	for (size_t r = 0; r < backgroundshapes.size(); r++)
	{
		window->draw(backgroundshapes[r]);
	}

	for (size_t r = 0; r < buildingshapes.size(); r++)
	{
		window->draw(buildingshapes[r]);
	}
}
