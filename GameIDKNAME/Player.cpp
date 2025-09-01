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

	gold = 10;
	silver = 100;
	copper = 1000;
	health = 20;

	if (!font.openFromFile("Fonts/PixeloidSans.ttf"))
	{
		std::cout << "Error: Can't load Font! -> Player_Init" << std::endl;
	}
	
	gold_text.emplace(font);
	gold_text->setCharacterSize(windowsize.x / 100);
	gold_text->setPosition({ windowsize.x / STATS_POS_INDEX,windowsize.y - (windowsize.y/40)});
	gold_text->setFillColor(color_gold);
	gold_text->setString("");

	silver_text.emplace(font);
	silver_text->setCharacterSize(windowsize.x / 100);
	silver_text->setPosition({ (windowsize.x / STATS_POS_INDEX)*2,windowsize.y - (windowsize.y / 40) });
	silver_text->setFillColor(color_silver);
	silver_text->setString("");

	copper_text.emplace(font);
	copper_text->setCharacterSize(windowsize.x / 100);
	copper_text->setPosition({ (windowsize.x / STATS_POS_INDEX)*3,windowsize.y - (windowsize.y / 40)});
	copper_text->setFillColor(color_copper);
	copper_text->setString("");

	health_text.emplace(font);
	health_text->setCharacterSize(windowsize.x / 100);
	health_text->setPosition({ (windowsize.x / STATS_POS_INDEX)*11,windowsize.y - (windowsize.y / 40)});
	health_text->setFillColor(color_health);
	health_text->setString("");
	
}

void Player::Player_Update()
{
	std::stringstream ss_gold, ss_silver, ss_copper, ss_health; 
	ss_gold << "Gold: " << gold << std::endl;
	ss_silver << "Silver: " << silver << std::endl;
	ss_copper << "Copper: " << copper << std::endl;
	ss_health << "Health: " << health << std::endl;

	gold_text->setString(ss_gold.str());
	silver_text->setString(ss_silver.str());
	copper_text->setString(ss_copper.str());
	health_text->setString(ss_health.str());
}

void Player::Player_Render(RenderWindow* window)
{
	window->draw(*copper_text);
	window->draw(*silver_text);
	window->draw(*gold_text);
	window->draw(*health_text);
}
