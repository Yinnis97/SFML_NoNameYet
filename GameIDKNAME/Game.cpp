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
	window = new RenderWindow(videomode, "DIKKE GAME", State::Fullscreen);
	window->setVerticalSyncEnabled(true);

	grid = new Grid(GetWindowSize());
	
	entities.push_back(new Boss(GetWindowSize()));
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

	grid->Grid_Update(GetupdateMousePos(),GetWindowSize());

	for (size_t e = 0; e < entities.size(); e++)
	{
		entities[e]->ChangeDirection(GetWindowSize());

			switch (entities[e]->direction)
			{
			case 0:
				entities[e]->sprite->move({ -(GetWindowSize().x / ENEMY_SPEED), 0 });
				break;
			case 1:
				entities[e]->sprite->move({ 0, (GetWindowSize().x / ENEMY_SPEED) });
				break;
			case 2:
				entities[e]->sprite->move({ 0, -(GetWindowSize().x / ENEMY_SPEED) });
				break;
			case 3:
				entities[e]->sprite->move({ (GetWindowSize().x / ENEMY_SPEED), 0 });
				break;
			default:
				std::cout << "Error Switch case Game::Update -> Entities direction" << std::endl;
				break;
			}
	}
}

void Game::Render()
{
	window->clear();
	
	// Render Grid and Towers
	grid->Grid_Render(this->window);

	// Render Enemies
	for (size_t e = 0; e < entities.size(); e++)
	{
		window->draw(*entities[e]->sprite);
	}

	window->display();
}
