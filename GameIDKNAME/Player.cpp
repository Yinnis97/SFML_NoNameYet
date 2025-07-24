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
	sprite.emplace(texture);
	sprite->setScale({ 2, 2 });
}

void Player::Move(char m)
{
	switch (m)
	{
	case 'Z':
		sprite->move({ 0, MoveSpeedneg });
		break;
	case 'S':
		sprite->move({ 0, MoveSpeedpos });
		break;
	case 'Q':
		sprite->move({ MoveSpeedneg, 0 });
		break;
	case 'D':
		sprite->move({ MoveSpeedpos, 0 });
		break;
	}
}

// Inputs :
//			s = Mouse position	(Vector2f)
//			w = window size		(Vector2f)
//			m = Mouse button	(bool)

void Player::Shoot(Vector2f s, Vector2f w, bool m)
{
	// Math 
	// Length of vector : |V| = sqrt(V.x² + V.x²)
	// Normalized Vector : U = V / |V|
	center = sprite->getPosition() + Vector2f{85, 81}; // TO DO FIX THIS, needs to be in the middle
	aimDirection = s - center;

	aimDirectionNorm.x = aimDirection.x / sqrt(pow(aimDirection.x, 2) + pow(aimDirection.y, 2));
	aimDirectionNorm.y = aimDirection.y / sqrt(pow(aimDirection.x, 2) + pow(aimDirection.y, 2));
	
	// Spawn bullets when mouse is being clicked/hold
	if(m)
	{
		Bullet b1(5.0);
		b1.shape.setPosition(center);
		b1.currVelocity = aimDirectionNorm * b1.speed;
		bullets.push_back(b1);
	}

	// Move bullets according to velocity
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].shape.move(bullets[i].currVelocity);
	}

	// Erase bullets when out off screen
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].shape.getPosition().x > w.x || bullets[i].shape.getPosition().x < 0 
			|| bullets[i].shape.getPosition().y > w.y || bullets[i].shape.getPosition().y < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::Update_Player(RenderWindow* window)
{
	if ( (sprite->getPosition().y) >= (window->getSize().y) )
	{
		sprite->setPosition({ 0 ,0 });
	}
}

void Player::Render_Player(RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		window->draw(bullets[i].shape);
	}

	window->draw(*sprite);
}

