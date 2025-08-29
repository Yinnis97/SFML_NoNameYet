#include "Entity.h"


uint8_t Entity::GetHealth()
{
    return this->health;
}

char Entity::GetID()
{
    return this->ID;
}

void Entity::TakeDmg(uint8_t dmg)
{
    this->health = this->health - dmg;
}

void Entity::ChangeDirection(Vector2f windowsize)
{
	// 0 = left , 1 = down , 2 = up, 3 = right

	if (sprite->getPosition().x <= (windowsize.x / 2) - (windowsize.y / 16) && !lastdir[0])
	{
		direction = 1;
		std::cout << "1\n";
		lastdir[0] = true;
	}
	else if (sprite->getPosition().y >= (windowsize.y / 2) - (windowsize.y/16) && !lastdir[1])
	{
		direction = 3;
		std::cout << "2\n";
		lastdir[1] = true;
	}
	else if (sprite->getPosition().x >= (windowsize.x - (windowsize.y / 8) - (windowsize.y /16)) && !lastdir[2] && lastdir[1])
	{
		direction = 1;
		std::cout << "3\n";
		lastdir[2] = true;
	}
	else if (sprite->getPosition().y >= (windowsize.y - (windowsize.y / 4) - (windowsize.y / 16)) && !lastdir[3] && lastdir[2])
	{
		direction = 0;
		std::cout << "4\n";
		lastdir[3] = true;
	}
	else if (sprite->getPosition().x <= (windowsize.x/2 - windowsize.y/4 - windowsize.y/16) && !lastdir[4] && lastdir[3])
	{
		direction = 2;
		std::cout << "5\n";
		lastdir[4] = true;
	}
	else if (sprite->getPosition().y <= (windowsize.y/8 + windowsize.y/16) && !lastdir[5] && lastdir[4])
	{
		direction = 0;
		std::cout << "6\n";
		lastdir[5] = true;
	}

}

void Entity::MoveEnemy(Vector2f windowsize)
{
	switch (direction)
	{
	case 0:
		sprite->move({ -(windowsize.x / ms), 0 });
		break;
	case 1:
		sprite->move({ 0, (windowsize.x / ms) });
		break;
	case 2:
		sprite->move({ 0, -(windowsize.x / ms) });
		break;
	case 3:
		sprite->move({ (windowsize.x / ms), 0 });
		break;
	default:
		std::cout << "Error Switch case Game::Update -> Entities direction" << std::endl;
		break;
	}
}

