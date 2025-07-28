#include "Boss.h"

void Boss::Init()
{
	texture.loadFromFile("Textures/EyeCharBlue.png");
	sprite.emplace(texture);
	sprite->setScale({ 3, 3 });
	sprite->setPosition({ 400,400 });
}
