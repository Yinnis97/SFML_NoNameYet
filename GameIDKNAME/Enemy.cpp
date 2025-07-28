#include "Enemy.h"

void Enemy::Init()
{
	texture.loadFromFile("Textures/EyeCharBlue.png");
	sprite.emplace(texture);
	sprite->setScale({ 1, 1 });
	sprite->setPosition({ 800,1000 });
}
