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

