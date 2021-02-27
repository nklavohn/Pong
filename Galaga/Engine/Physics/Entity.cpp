#include "Entity.h"

Entity::Entity()
{
	pos = Vector2::ZERO;
	vel = Vector2::ZERO;
	cDetector = nullptr;
}

Entity::Entity(Vector2 _pos)
{
	pos = _pos;
	vel = Vector2::ZERO;
	cDetector = nullptr;
}

Entity::~Entity()
{

}

bool Entity::IsCollidingWith(Vector2 point)
{
	return cDetector->IsPointInside(point);
}

bool Entity::IsCollidingWith(CollisionDetector* _cDetector)
{
	return cDetector->IsCollidingWith(_cDetector);
}

CollisionDetector* Entity::GetCollisionDetector()
{
	return cDetector;
}

void Entity::SetCollisionDetector(CollisionDetector* _cDetector)
{
	cDetector = _cDetector;
}

void Entity::SetPos(const Vector2& _pos)
{
	pos = _pos;
}

void Entity::SetVel(const Vector2& _vel)
{
	vel = _vel;
}
