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
}

void Game::Init_Window()
{
	videomode = VideoMode::getDesktopMode();
	window = new RenderWindow(videomode, "DIKKE GAME", State::Windowed);
	window->setVerticalSyncEnabled(true);
	clock.restart();
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
    return static_cast<Vector2f>(this->window->getSize());
}

const Vector2f Game::GetupdateMousePos()
{
	return window->mapPixelToCoords(Mouse::getPosition(*this->window));
}

void Game::Update()
{
	Pollevents();

	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		player.Shoot(GetupdateMousePos(), GetWindowSize(),1);
	}
	else
	{
		player.Shoot(GetupdateMousePos(), GetWindowSize(),0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Scancode::W))
		player.Move('Z');
	if (Keyboard::isKeyPressed(Keyboard::Scancode::A))
		player.Move('Q');
	if (Keyboard::isKeyPressed(Keyboard::Scancode::S))
		player.Move('S');
	if (Keyboard::isKeyPressed(Keyboard::Scancode::D))
		player.Move('D');

	player.Update_Player(window);
}

void Game::Render()
{
	window->clear();

	player.Render_Player(window);

	window->display();
}
