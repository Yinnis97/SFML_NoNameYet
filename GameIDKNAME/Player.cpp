#include "Player.h"

Player::Player()
{
	Init_();
}

Player::~Player()
{
}

void Player::Init_()
{
	if (!texture.loadFromFile("Textures/EyeCharBlue.png"))
	{
		std::cout << "Error Loading Texture" << "\n";
	}
	texture.setSmooth(0);

	sprite.emplace(texture);
	//sprite->setPosition({ 500, 500});
	sprite->setScale({ 2, 2 });
	
}

void Player::Update_Player(RenderWindow* window)
{
	
	sprite->move({ 1,1 });
	if ( (sprite->getPosition().y) >= (window->getSize().y) )
	{
		sprite->setPosition({ 0 ,0 });
	}
}

void Player::Render_Player(RenderWindow* window)
{
	window->draw(*sprite);
}

