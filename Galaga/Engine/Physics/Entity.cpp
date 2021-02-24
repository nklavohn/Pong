#include "Entity.h"

Entity::Entity()
{
	pos = Vector2::ZERO;
	cDetector = nullptr;
}

Entity::Entity(Vector2 _pos, CollisionDetector& _cDetector)
{
	pos = _pos;
	cDetector = &_cDetector;
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
