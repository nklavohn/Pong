#include "SmallShot.h"

SmallShot::SmallShot() : Entity(PROJECTILE)
{

}

SmallShot::SmallShot(Vector2 _pos, Vector2 _vel) : Entity(PROJECTILE)
{
	hitbox = new PointHitbox(_pos);
}

SmallShot::~SmallShot()
{

}


void SmallShot::Move()
{

}

void SmallShot::Render() const
{

}

void SmallShot::DebugPhysics() const
{

}