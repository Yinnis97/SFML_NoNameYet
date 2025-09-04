#include "Menu.h"

Menu::Menu(Vector2f windowsize)
{
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
}

void Menu::Menu_SaveGame()
{
}

void Menu::Menu_LoadGame()
{
}

void Menu::Menu_Update(Vector2f windowsize)
{

}

void Menu::Menu_Render(RenderWindow* window)
{
	window->draw(background);
}
