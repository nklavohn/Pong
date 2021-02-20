#include "Entity.h"

Entity::Entity()
{
	pos = Vector2::ZERO;
	hitbox = Hitbox();
}

Entity::Entity(Vector2 _pos, Vector2 hitboxCenter, Vector2 hitboxDim)
{
	pos = _pos;
	hitbox = Hitbox(hitboxCenter, hitboxDim);
}

Entity::Entity(Vector2 _pos, Vector4 _hitbox)
{
	pos = _pos;
	hitbox = Hitbox(_hitbox);
}

Entity::Entity(Vector2 _pos, Hitbox _hitbox)
{
	pos = _pos;
	hitbox = _hitbox;
}

Entity::~Entity()
{

}

bool Entity::IsCollidingWith(Vector2 point, bool inclusive)
{
	return hitbox.IsPointInside(point, inclusive);
}

bool Entity::IsCollidingWith(Vector4 box, bool inclusive)
{
	return hitbox.DoesBoxOverlap(box, inclusive);
}

Hitbox Entity::GetHitbox()
{
	return hitbox;
}
