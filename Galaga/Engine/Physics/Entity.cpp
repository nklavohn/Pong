#include "Entity.h"
#include "Engine/Graphics/ShapeRenderer.h"

int Entity::NEXT_ID = 0;

Entity::Entity()
{
	pos = Vector2::ZERO;
	spriteSheet = SpriteSheet();
	Initialize();
}

Entity::Entity(const Vector2& _pos, const SpriteSheet& _spriteSheet)
{
	pos = _pos;
	spriteSheet = _spriteSheet;
	Initialize();
}

Entity::~Entity()
{
	delete cDetector;
}

void Entity::Initialize()
{
	prevPos = pos;

	id = Entity::GetNextID();
	vel = Vector2::ZERO;
	accel = Vector2::ZERO;
	cDetector = nullptr;
	currentSprite = IVector2::ZERO;

	speed = 0;
	maxSpeed = 0;
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
	cDetector->Render(Color::WHITE);
	std::cout << "It does run here" << std::endl;
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

void Entity::FlagForRemoval(const bool& flag)
{
	isFlaggedForRemoval = flag;
}

void Entity::DebugPhysicsDefault() const
{
	if (cDetector) cDetector->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::BLUE, pos, pos + vel);
	ShapeRenderer::DrawVector(Color::MAGENTA, pos, pos + accel);
}

int Entity::GetNextID()
{
	return NEXT_ID++;
}