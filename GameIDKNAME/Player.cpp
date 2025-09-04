#include "Player.h"

Player::Player(Vector2f windowsize)
{
	Player_Init(windowsize);
}

Player::~Player()
{
}

void Player::Player_Init(Vector2f windowsize)
{
	Color color_health(150,0,0,255);
	Color color_copper(184, 115, 51, 255);
	Color color_silver(192,192,192,255);
	Color color_gold(211,175,55,255);
	Color color_blue_sapphire(0,99,213,255);
	Color color_green_sapphire(0,183,10,255);
	Color color_yellow_sapphire(224,232,0,255);
	Color color_orange_sapphire(225, 110, 0,255);

	gold = 10;
	silver = 100;
	copper = 1000;
	health = 1000;

	blue_sapphire = 0;
	green_sapphire = 0;
	yellow_sapphire = 0;
	orange_sapphire = 0;

	if (!font.openFromFile("Fonts/PixeloidSans.ttf"))
	{
		std::cout << "Error: Can't load Font! -> Player_Init" << std::endl;
	}

	spacing = windowsize.x / 25;
	

	gold_text.emplace(font);
	gold_text->setCharacterSize(windowsize.x / 100);
	gold_text->setPosition({spacing, windowsize.y - (windowsize.y/40)});
	gold_text->setFillColor(color_gold);
	gold_text->setString("");

	silver_text.emplace(font);
	silver_text->setCharacterSize(windowsize.x / 100);
	silver_text->setPosition({ (gold_text->getGlobalBounds().position.x + gold_text->getGlobalBounds().size.x) + spacing, windowsize.y - (windowsize.y / 40) });
	silver_text->setFillColor(color_silver);
	silver_text->setString("");

	copper_text.emplace(font);
	copper_text->setCharacterSize(windowsize.x / 100);
	copper_text->setPosition({ (silver_text->getGlobalBounds().position.x + silver_text->getGlobalBounds().size.x) + spacing, windowsize.y - (windowsize.y / 40)});
	copper_text->setFillColor(color_copper);
	copper_text->setString("");

	health_text.emplace(font);
	health_text->setCharacterSize(windowsize.x / 100);
	health_text->setPosition({ (windowsize.x / STATS_POS_INDEX) * 11,windowsize.y - (windowsize.y / 40)});
	health_text->setFillColor(color_health);
	health_text->setString("");

	blue_sapphire_text.emplace(font);
	blue_sapphire_text->setCharacterSize(windowsize.x / 100);
	blue_sapphire_text->setPosition({ (copper_text->getGlobalBounds().position.x + copper_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	blue_sapphire_text->setFillColor(color_blue_sapphire);
	blue_sapphire_text->setString("");

	green_sapphire_text.emplace(font);
	green_sapphire_text->setCharacterSize(windowsize.x / 100);
	green_sapphire_text->setPosition({ (blue_sapphire_text->getGlobalBounds().position.x + blue_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	green_sapphire_text->setFillColor(color_green_sapphire);
	green_sapphire_text->setString("");

	yellow_sapphire_text.emplace(font);
	yellow_sapphire_text->setCharacterSize(windowsize.x / 100);
	yellow_sapphire_text->setPosition({ (green_sapphire_text->getGlobalBounds().position.x + green_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	yellow_sapphire_text->setFillColor(color_yellow_sapphire);
	yellow_sapphire_text->setString("");

	orange_sapphire_text.emplace(font);
	orange_sapphire_text->setCharacterSize(windowsize.x / 100);
	orange_sapphire_text->setPosition({ (yellow_sapphire_text->getGlobalBounds().position.x + yellow_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	orange_sapphire_text->setFillColor(color_orange_sapphire);
	orange_sapphire_text->setString("");
}

void Player::Player_Proccess_Loot(Vector2u loot)
{
	switch (loot.x)
	{
	case 1:
		blue_sapphire = blue_sapphire + loot.y;
		break;
	case 2:
		green_sapphire = green_sapphire + loot.y;
		break;
	case 3:
		yellow_sapphire = yellow_sapphire + loot.y;
		break;
	case 4:
		orange_sapphire = orange_sapphire + loot.y;
		break;
	}
}

void Player::Player_Update(Vector2f windowsize)
{
	std::stringstream ss_gold, ss_silver, ss_copper, ss_health, ss_b_sapphire, ss_g_sapphire, ss_y_sapphire, ss_o_sapphire; 
	ss_gold << "Gold: " << gold << std::endl;
	ss_silver << "Silver: " << silver << std::endl;
	ss_copper << "Copper: " << copper << std::endl;
	ss_health << "Health: " << health << std::endl;

	ss_b_sapphire << "Blue Sapphire: " << blue_sapphire << std::endl;
	ss_g_sapphire << "Green Sapphire: " << green_sapphire << std::endl;
	ss_y_sapphire << "Yellow Sapphire: " << yellow_sapphire << std::endl;
	ss_o_sapphire << "Orange Sapphire: " << orange_sapphire << std::endl;

	gold_text->setString(ss_gold.str());
	silver_text->setString(ss_silver.str());
	copper_text->setString(ss_copper.str());
	health_text->setString(ss_health.str());

	blue_sapphire_text->setString(ss_b_sapphire.str());
	green_sapphire_text->setString(ss_g_sapphire.str());
	yellow_sapphire_text->setString(ss_y_sapphire.str());
	orange_sapphire_text->setString(ss_o_sapphire.str());

	silver_text->setPosition({ (gold_text->getGlobalBounds().position.x + gold_text->getGlobalBounds().size.x) + spacing, windowsize.y - (windowsize.y / 40) });
	copper_text->setPosition({ (silver_text->getGlobalBounds().position.x + silver_text->getGlobalBounds().size.x) + spacing, windowsize.y - (windowsize.y / 40) });
	blue_sapphire_text->setPosition({ (copper_text->getGlobalBounds().position.x + copper_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	green_sapphire_text->setPosition({ (blue_sapphire_text->getGlobalBounds().position.x + blue_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	yellow_sapphire_text->setPosition({ (green_sapphire_text->getGlobalBounds().position.x + green_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
	orange_sapphire_text->setPosition({ (yellow_sapphire_text->getGlobalBounds().position.x + yellow_sapphire_text->getGlobalBounds().size.x) + spacing,windowsize.y - (windowsize.y / 40) });
}

void Player::Player_Render(RenderWindow* window)
{
	window->draw(*copper_text);
	window->draw(*silver_text);
	window->draw(*gold_text);
	window->draw(*health_text);
	window->draw(*blue_sapphire_text);
	window->draw(*green_sapphire_text);
	window->draw(*yellow_sapphire_text);
	window->draw(*orange_sapphire_text);
}
