#include "Projectile.h"

Projectile::Projectile(std::unique_ptr<Hitbox> _hitbox) : Entity(PROJECTILE), PhysicsObject(std::move(_hitbox))
{

}

Projectile::~Projectile()
{

}