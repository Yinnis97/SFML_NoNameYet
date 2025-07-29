#include "Grid.h"

Grid::Grid(Vector2f windowsize)
{
	Grid_Init(windowsize);
	mousepressed = false;
}

Grid::~Grid()
{
}

void Grid::Grid_Init(Vector2f windowsize)
{
	// Load Textures
	sandTexture.loadFromFile("Textures/DonkerGeel.png");
	grassTexture.loadFromFile("Textures/DonkerGroen.png");
	waterTexture.loadFromFile("Textures/DonkerBlauw.png");
	sectionTexture.loadFromFile("Textures/Grijs.png");
	grassTexture.setRepeated(true);
	sandTexture.setRepeated(true);
	waterTexture.setRepeated(true);
	sectionTexture.setRepeated(true);

	// Background YELLOW
	sand.setTexture(&sandTexture);
	sand.setSize(windowsize);
	sand.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y) }));
	
	// Wall GREEN TOP
	top.setTexture(&grassTexture);
	top.setSize({ windowsize.x,  windowsize.y / 8 });
	top.setPosition({ 0,0});
	top.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y / 8) }));
	top.setOutlineColor(Color::Black);
	top.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(top);

	// Wall GREEN HORIZONTAL SECOND
	second.setTexture(&grassTexture);
	second.setSize({ windowsize.x / 2,  windowsize.y / 8 });
	second.setPosition({ windowsize.x / 2,windowsize.y /4}); 
	second.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x / 2), static_cast<int>(windowsize.y / 8) }));
	second.setOutlineColor(Color::Black);
	second.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(second);

	// Wall GREEN HORIZONTAL THIRD
	third.setTexture(&grassTexture);
	third.setSize({ windowsize.x / 2 - (windowsize.y / 8),  windowsize.y / 8});
	third.setPosition({ windowsize.x / 2 - (windowsize.y / 8),windowsize.y / 2});
	third.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x / 2 - (windowsize.y / 8)), static_cast<int>(windowsize.y / 8) }));
	third.setOutlineColor(Color::Black);
	third.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(third);

	// Wall GREEN VERTICAL MIDDLE
	vertmid.setTexture(&grassTexture);
	vertmid.setSize({ windowsize.y / 8,  windowsize.y / 2 });
	vertmid.setPosition({ (windowsize.x / 2) - (windowsize.y/4),windowsize.y / 8 });
	vertmid.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.y / 8), static_cast<int>(windowsize.y/2) }));
	vertmid.setOutlineColor(Color::Black);
	vertmid.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(vertmid);

	// Wall GREEN VERTICAL RIGHT
	vertright.setTexture(&grassTexture);
	vertright.setSize({ windowsize.y / 8,  windowsize.y/2 - (windowsize.y/8)}); 
	vertright.setPosition({ (windowsize.x - (windowsize.y/8)),(windowsize.y / 2)-(windowsize.y /8)});
	vertright.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.y / 8), static_cast<int>((windowsize.y/2) + (windowsize.y / 8)) }));
	vertright.setOutlineColor(Color::Black);
	vertright.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(vertright);

	// Wall GREEN BOTTOM
	bottom.setTexture(&grassTexture);
	bottom.setSize({ windowsize.x,  windowsize.y/8 });
	bottom.setPosition({0, windowsize.y / 2 + (windowsize.y / 4) });
	bottom.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y/8) }));
	bottom.setOutlineColor(Color::Black);
	bottom.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(bottom);

	// Wall GREEN CUBE
	cube.setTexture(&grassTexture);
	cube.setSize({ (windowsize.y / 2)+(windowsize.y/32), (windowsize.y / 2)}); // size x needs to be fixed.
	cube.setPosition({ (windowsize.x / 2) - (windowsize.y / 4) - (windowsize.y / 8),(windowsize.y / 4) });
	cube.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y / 8) }));
	cube.setOrigin({ cube.getSize().x,0 }); // Makes it easier to have the same size enemy paths.
	cube.setOutlineColor(Color::Black);
	cube.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(cube);

	// BOTTOM SECTION
	section.setTexture(&sectionTexture);
	section.setSize({ windowsize.x, windowsize.y / 8 }); 
	section.setPosition({ 0, bottom.getPosition().y + (windowsize.y /8)});
	section.setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(windowsize.x), static_cast<int>(windowsize.y / 8) }));
	section.setOutlineColor(Color::Black);
	section.setOutlineThickness(LINETHICKNESS);
	backgroundshapes.push_back(section);

	buildplot bottom;
	buildplots.push_back(bottom);

	// Building squares
	float k = 0;
	for (size_t s = 0; s <= 10; s++)
	{
		buildplot bottom;
		bottom.build = false;
		bottom.shape.setFillColor(Color::Yellow);
		bottom.shape.setOutlineColor(Color::Black);
		bottom.shape.setOutlineThickness(windowsize.x/1000);
		bottom.shape.setSize({ windowsize.x/20, windowsize.x/20 });
		bottom.shape.setPosition({(windowsize.x/40)+k,windowsize.y - (windowsize.y/9)});
		buildplots.push_back(bottom);
		k = k + (windowsize.x / 10);
	}
}

void Grid::Grid_Update(Vector2f Mousepos,Vector2f windowsize)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		if (!mousepressed)
		{
			mousepressed = true;
			for (size_t m = 0; m < buildplots.size(); m++)
			{
				if (buildplots[m].shape.getGlobalBounds().contains(Mousepos) && (!buildplots[m].build))
				{
					// fix so u can pick what tower to build ------
					towers.push_back(new Turret(buildplots[m].shape.getPosition(), { windowsize.x / 20, windowsize.x / 20 }));
					buildplots[m].build = true;
				}
			}
		}
	}
	else
	{
		mousepressed = false;
	}

	// Update towers
	for (size_t t = 0; t < towers.size(); t++)
	{
		towers[t]->Tower_Update(windowsize);
	}
}

void Grid::Grid_Render(RenderWindow* window)
{
	// Render yellow background 
	window->draw(sand);

	// Render green areas
	for (size_t r = 0; r < backgroundshapes.size(); r++)
	{
		window->draw(backgroundshapes[r]);
	}

	// Render construction sites
	for (size_t r = 0; r < buildplots.size(); r++)
	{
		window->draw(buildplots[r].shape);
	}

	// Render towers
	for (size_t t = 0; t < towers.size(); t++)
	{
		towers[t]->Tower_Render(window);
	}
}
