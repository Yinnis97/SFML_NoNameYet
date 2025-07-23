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
				std::cout << "Escape\n";
				break;
			}
		}
	}
}

void Game::Update()
{
	Pollevents();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
		player.Move('Z');
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
		player.Move('Q');
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
		player.Move('S');
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
		player.Move('D');

	player.Update_Player(window);
}

void Game::Render()
{
	window->clear();

	player.Render_Player(window);

	window->display();
}
