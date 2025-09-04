#include "Menu.h"

Menu::Menu(Vector2f windowsize)
{
	mousepressed = false;
	Menu_Init(windowsize);
}

Menu::~Menu()
{

}

void Menu::Menu_Init(Vector2f windowsize)
{
	background_texture.loadFromFile("Textures/backgroundMenu.png");
	background.setTexture(&background_texture);
	background.setSize(windowsize);
	background.setPosition({ 0,0 });

	Color start_button_color(96,96,96,255);

	startbutton.setFillColor(start_button_color);
	startbutton.setOutlineThickness(windowsize.x / 2000);
	startbutton.setOutlineColor(Color::Black);
	startbutton.setSize({ windowsize.x / 10, windowsize.y / 20 });
	startbutton.setOrigin({ startbutton.getSize().x / 2, startbutton.getSize().y / 2 });
	startbutton.setPosition({ windowsize.x / 2,windowsize.y / 2 });
	
}

void Menu::Menu_SaveGame()
{

}

void Menu::Menu_LoadGame()
{

}

void Menu::Menu_Update(Vector2f mousepos, Vector2f windowsize, bool* inMenu)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		if (!mousepressed)
		{
			mousepressed = true;
			if (startbutton.getGlobalBounds().contains(mousepos))
			{
				std::cout << "pressed\n";
				*inMenu = false;
			}
		}
	}
	else
	{
		mousepressed = false;
	}
}

void Menu::Menu_Render(RenderWindow* window)
{
	window->draw(background);
	window->draw(startbutton);
}
