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
	//Color color(0,44,82,255);
	
	gold = 10;
	silver = 100;
	copper = 1000;

	if (!font.openFromFile("Fonts/PixeloidSans.ttf"))
	{
		std::cout << "Error: Can't load Font! -> Player_Init" << std::endl;
	}

	gold_text.emplace(font);
	gold_text->setCharacterSize(windowsize.x / 100);
	gold_text->setPosition({ windowsize.x/ STATS_POS_INDEX,windowsize.y - (windowsize.y/40)});
	gold_text->setFillColor(Color::Yellow);
	gold_text->setString("");

	silver_text.emplace(font);
	silver_text->setCharacterSize(windowsize.x / 100);
	silver_text->setPosition({ (windowsize.x / STATS_POS_INDEX)*2,windowsize.y - (windowsize.y / 40) });
	silver_text->setFillColor(Color::Yellow);
	silver_text->setString("");

	copper_text.emplace(font);
	copper_text->setCharacterSize(windowsize.x / 100);
	copper_text->setPosition({ (windowsize.x / STATS_POS_INDEX)*3,windowsize.y - (windowsize.y / 40)});
	copper_text->setFillColor(Color::Yellow);
	copper_text->setString("");
}

void Player::Player_Update()
{
	std::stringstream ss_gold, ss_silver, ss_copper; 
	ss_gold << "Gold: " << gold << std::endl;
	ss_silver << "Silver: " << silver << std::endl;
	ss_copper << "Copper: " << copper << std::endl;

	gold_text->setString(ss_gold.str());
	silver_text->setString(ss_silver.str());
	copper_text->setString(ss_copper.str());
}

void Player::Player_Render(RenderWindow* window)
{
	window->draw(*copper_text);
	window->draw(*silver_text);
	window->draw(*gold_text);
}
