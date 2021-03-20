#include "Enemy.h"

Enemy::Enemy() : Entity(ENEMY)
{

}

Enemy::Enemy(const SpriteSheet sheet) : Entity(ENEMY, sheet)
{

}

Enemy::~Enemy()
{

}