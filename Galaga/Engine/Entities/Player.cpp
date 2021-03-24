#include "Player.h"

Player::Player(std::unique_ptr<Hitbox> _hitbox) : Entity(PLAYER), PhysicsObject(std::move(_hitbox))
{

}

Player::~Player()
{

}