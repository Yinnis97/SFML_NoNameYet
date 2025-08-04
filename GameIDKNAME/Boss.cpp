#include "Boss.h"

void Boss::Init()
{
	texture.loadFromFile("Textures/EyeCharBlue.png");
	sprite.emplace(texture);
	sprite->setScale({ 2, 2 });
	sprite->setOrigin({ sprite->getLocalBounds().getCenter()});
	sprite->setPosition({ startpos.x,(startpos.y / 8) + (startpos.y/16)});
}