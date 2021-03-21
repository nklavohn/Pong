#include "Entity.h"
#include "Engine/Graphics/ShapeRenderer.h"

int Entity::NEXT_ID = 0;

Entity::Entity(const enum Category _category) : id(GetNextID()), category(_category)
{
	spriteSheet = SpriteSheet();
	Initialize();
}

Entity::Entity(const enum Category _category, const SpriteSheet& _spriteSheet) : id(GetNextID()), category(_category)
{
	spriteSheet = _spriteSheet;
	Initialize();
}

Entity::~Entity()
{
	delete hitbox;
}

void Entity::Initialize()
{
	prevPos = Vector2::ZERO;
	vel = Vector2::ZERO;
	accel = Vector2::ZERO;
	hitbox = nullptr;
	currentSprite = IVector2::ZERO;

	speed = 0;
	maxSpeed = 0;
	spawnQueue = defaultSpawnQueue;
}

bool Entity::IsCollidingWith(const Vector2& point) const
{
	return hitbox->IsPointInside(point);
}

bool Entity::IsCollidingWith(Entity* other) const
{
	return hitbox->IsCollidingWith(other->GetHitbox());
}

Hitbox* Entity::GetHitbox()
{
	return hitbox;
}

void Entity::SetHitbox(Hitbox* _hitbox)
{
	hitbox = _hitbox;
}

void Entity::SetPos(const Vector2& _pos)
{
	hitbox->SetCenter(_pos);
}

void Entity::SetVel(const Vector2& _vel)
{
	vel = _vel;
}

void Entity::SetAccel(const Vector2& _accel)
{
	accel = _accel;
}

bool Entity::IsFlaggedForRemoval() const
{
	return isFlaggedForRemoval;
}

void Entity::FlagForRemoval(const bool& flag)
{
	isFlaggedForRemoval = flag;
}

void Entity::DebugPhysicsDefault() const
{
	Vector2 pos = hitbox->GetCenter();
	if (hitbox) hitbox->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::BLUE, pos, pos + vel);
	ShapeRenderer::DrawVector(Color::MAGENTA, pos, pos + accel);
}

int Entity::GetNextID()
{
	return NEXT_ID++;
}

void Entity::SetDefaultSpawnQueue(const std::shared_ptr<entity_queue<Entity>> newDefault)
{
	defaultSpawnQueue = newDefault;
}

void Entity::SetSpawnQueue(const std::shared_ptr<entity_queue<Entity>> sQueue)
{
	spawnQueue = sQueue;
}