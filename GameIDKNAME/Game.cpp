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
	shape.setRadius(500.0);
	shape.setFillColor(Color::Green);
	shape.setOutlineColor(Color::Cyan);
	window = nullptr;
}

void Game::Init_Window()
{
	videomode = VideoMode::getDesktopMode();
	window = new RenderWindow(videomode, "DIKKE GAME", State::Windowed);
	window->setVerticalSyncEnabled(true);
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
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				window->close();
		}
	}
}

void Game::Update()
{
	Pollevents();
	player.Update_Player();
}

void Game::Render()
{
	window->clear();

	player.Render_Player(window);

	window->display();
}
