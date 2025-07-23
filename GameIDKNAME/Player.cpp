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
	texture = std::make_unique<sf::Texture>("Textures/EyeCharBlue.png");
	sprite = std::make_unique<sf::Sprite>(*texture);
}

void Player::Update_Player()
{
}

void Player::Render_Player(RenderWindow* window)
{
	window->draw(*sprite);
}

