#include "HitboxedObject.h"

HitboxedObject::HitboxedObject(std::unique_ptr<Hitbox> _hitbox)
{
	hitbox = std::move(_hitbox);
}

HitboxedObject::~HitboxedObject()
{

}

Hitbox* HitboxedObject::GetHitbox() const
{ 
	return hitbox.get();
}

void HitboxedObject::SetHitbox(std::unique_ptr<Hitbox> _hitbox)
{
	hitbox = std::move(_hitbox);
}

bool HitboxedObject::IsCollidingWith(const Vector2& point) const
{
	return hitbox->IsPointInside(point);
}

bool HitboxedObject::IsCollidingWith(HitboxedObject* other) const
{
	return hitbox->IsCollidingWith(other->GetHitbox());
}