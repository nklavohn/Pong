#include "Enemy.h"

Enemy::Enemy(std::unique_ptr<Hitbox> _hitbox) : Entity(ENEMY), PhysicsObject(std::move(_hitbox))
{

}

Enemy::~Enemy()
{

}