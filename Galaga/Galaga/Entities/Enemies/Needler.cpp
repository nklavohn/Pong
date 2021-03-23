#include "Needler.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Engine.h"
#include "Engine/Math/Camera.h"
#include "Engine/Physics/RectHitbox.h"

Needler::Needler() : Entity(ENEMY)
{

}

Needler::Needler(const Vector2& _pos) : Entity(ENEMY, SpriteSheet("Galaga/Assets/needler.png", IVector2(19, 25)))
{
	maxSpeed = 200;
	speed = maxSpeed;
	vel = Vector2(speed, 0);
	hitbox = new RectHitbox(_pos, Vector2(19, 25));
}

Needler::~Needler()
{

}

void Needler::Move()
{
	Vector2 pos = hitbox->GetCenter();
	prevPos = pos;
	pos += vel * Engine::GetDeltaTime();

	Vector4 bounds = Camera::GetVisibleBounds();
	int code = Vector2::Constrain(&pos, bounds.x, bounds.z, bounds.y, bounds.w);

	if (code != -1)
	{
		vel *= -1;
	}

	hitbox->SetCenter(pos);
}

void Needler::Render() const
{
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), currentSprite);
}

void Needler::DebugPhysics() const
{
	DebugPhysicsDefault();
}