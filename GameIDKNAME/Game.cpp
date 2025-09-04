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

	srand(time(NULL));

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

const Vector2f Game::GetMousePos()
{
	return window->mapPixelToCoords(Mouse::getPosition(*this->window));
}

void Game::EntitySpawn()
{
	if (clock.getElapsedTime().asMilliseconds() >= 1000)
	{
		uint8_t random = rand() % 100;

		switch (random)
		{
		case 99:
			entities.push_back(new Boss(GetWindowSize()));
			break;
		default:
			entities.push_back(new Enemy(GetWindowSize()));
			break;
		}
		clock.restart();
	}
}

void Game::EntityHitDetection(size_t index)
{
	bool entityDied = false;

	// Check if entities have been hit by bullets
	for (size_t i = 0; i < grid->towers.size(); i++)
	{
		for (size_t j = 0; j < grid->towers[i]->bullets.size(); j++)
		{
			if (entities[index]->sprite->getGlobalBounds().contains(grid->towers[i]->bullets[j].shape.getPosition()))
			{
				entities[index]->TakeDmg(grid->towers[i]->bullets[j].damage);
				grid->towers[i]->bullets.erase(grid->towers[i]->bullets.begin() + j);
				
				if (entities[index]->GetHealth() <= 0)
				{
					entityDied = true;
				}
				break;
			}
		}
	}

	if (entityDied)
	{
		switch (entities[index]->GetID())
		{
		case 'E':
			player->copper = player->copper + 1;
			break;
		case 'B':
			player->gold = player->gold + 1;
			break;
		default:
			std::cout << "Error at switch case entities GetID\n";
			break;
		}

		player->Player_Proccess_Loot(entities[index]->DropLoot());

		entities.erase(entities.begin() + index);
	}
}

void Game::EntityEscaped(size_t index)
{
	if (entities[index]->sprite->getPosition().x < 0)
	{
		entities.erase(entities.begin() + index);
		player->health = player->health - 1;
	}
}

void Game::Update()
{
	Pollevents();
	EntitySpawn();

	player->Player_Update(GetWindowSize());
	grid->Grid_Update(GetMousePos(),GetWindowSize());

	for (size_t index = 0; index < entities.size(); index++)
	{
		entities[index]->ChangeDirection(GetWindowSize());
		entities[index]->MoveEnemy(GetWindowSize());

		EntityHitDetection(index);
	}

	for (size_t index = 0; index < entities.size(); index++)
	{
		EntityEscaped(index);
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
