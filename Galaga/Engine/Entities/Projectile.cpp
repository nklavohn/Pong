#include "Projectile.h"

Projectile::Projectile() : Entity(PROJECTILE)
{

}

Projectile::Projectile(const SpriteSheet sheet) : Entity(PROJECTILE, sheet)
{

}

Projectile::~Projectile()
{

}