#include "Entity.h"
#include "Engine/Graphics/ShapeRenderer.h"

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

bool Entity::IsCollidingWith(const Vector2& point) const
{
	return cDetector->IsPointInside(point);
}

bool Entity::IsCollidingWith(Entity* other) const
{
	return cDetector->IsCollidingWith(other->GetCollisionDetector());
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

void Entity::SetAccel(const Vector2& _accel)
{
	accel = _accel;
}

bool Entity::NeedsToBeRemoved() const
{
	return isFlaggedForRemoval;
}

bool Entity::FlagForRemoval(const bool& flag)
{
	isFlaggedForRemoval = flag;
}

void Entity::DebugPhysicsDefault() const
{
	cDetector->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::BLUE, pos, pos + vel);
	ShapeRenderer::DrawVector(Color::MAGENTA, pos, pos + accel);
}