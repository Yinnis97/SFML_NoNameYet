#include "Game.h"

Game::Game()
{
	Init_Var();
	Init_Window();
	Init_Background();
}

Game::~Game()
{
}

void Game::Init_Var()
{
	window = nullptr;
	mouseheld = false;
}
void Game::Init_Window()
{
	videomode = VideoMode::getDesktopMode();
	window = new RenderWindow(videomode, "DIKKE GAME", State::Windowed);
	window->setVerticalSyncEnabled(true);

	grid = new Grid(GetWindowSize());
	
	entities.push_back(new Boss);
	towers.push_back(new Rocket({ 1000,100 }));
	towers.push_back(new Sniper({ 1500,100 }));
	towers.push_back(new Turret({ 2000,100 }));
}


void Game::Init_Background()
{
	// Make a shader for background
}

bool Game::Running()
{
	return window->isOpen();
}

void Game::Pollevents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			switch (keyPressed->scancode)
			{
			case Keyboard::Scancode::Escape:
				window->close();
				break;
			}
		}
	}
}

const Vector2f Game::GetWindowSize()
{
	//std::cout << this->window->getSize().x << " " << this->window->getSize().y << std::endl;
    return static_cast<Vector2f>(this->window->getSize());
}

const Vector2f Game::GetupdateMousePos()
{
	return window->mapPixelToCoords(Mouse::getPosition(*this->window));
}

void Game::Update()
{
	Pollevents();

	// Update towers
	for (size_t t = 0; t < towers.size(); t++)
	{
		towers[t]->Tower_Update(GetWindowSize());
	}
}

void Game::Render()
{
	window->clear();

	// Render Towers
	for (size_t t = 0; t < towers.size(); t++)
	{
		towers[t]->Tower_Render(this->window);
	}

	// Render Enemies
	/*
	for (size_t e = 0; e < entities.size(); e++)
	{
		window->draw(*entities[e]->sprite);
	}*/
	
	grid->Grid_Render(this->window);
	window->display();
}
