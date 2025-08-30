#include "Game.h"

Game::Game()
{
	Init_Var();
	Init_Window();
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
	window = new RenderWindow(videomode, "DIKKE GAME", State::Fullscreen);
	window->setVerticalSyncEnabled(true);

	grid = new Grid(GetWindowSize());
	player = new Player(GetWindowSize());
	clock.restart();
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
    return static_cast<Vector2f>(this->window->getSize());
}

const Vector2f Game::GetupdateMousePos()
{
	return window->mapPixelToCoords(Mouse::getPosition(*this->window));
}

void Game::SpawnEnemies()
{
	for (size_t i = 0; i < 20; i++)
	{
	}

	if (clock.getElapsedTime().asMilliseconds() >= 1000)
	{
		entities.push_back(new Boss(GetWindowSize()));
		clock.restart();
	}
}

void Game::Update()
{
	Pollevents();
	SpawnEnemies();

	player->Player_Update();
	grid->Grid_Update(GetupdateMousePos(),GetWindowSize());

	for (size_t e = 0; e < entities.size(); e++)
	{
		// Move and change direction if necessary
		entities[e]->ChangeDirection(GetWindowSize());
		entities[e]->MoveEnemy(GetWindowSize());
		
		// Check if entities have been hit by bullets
		for (size_t i = 0; i < grid->towers.size(); i++)
		{
			for (size_t j = 0; j < grid->towers[i]->bullets.size(); j++)
			{
				if (entities[e]->sprite->getGlobalBounds().contains(grid->towers[i]->bullets[j].shape.getPosition()))
				{
					entities.erase(entities.begin() + e);
					grid->towers[i]->bullets.erase(grid->towers[i]->bullets.begin() + j);
					player->gold = player->gold + 1;
					break;
				}
			}
		}
	}
}

void Game::Render()
{
	window->clear();
	
	grid->Grid_Render(this->window);

	player->Player_Render(this->window);

	for (size_t e = 0; e < entities.size(); e++)
	{
		window->draw(*entities[e]->sprite);
	}

	window->display();
}
