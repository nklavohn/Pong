#include "Needler.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Engine.h"
#include "Engine/Math/Camera.h"

Needler::Needler()
{

}

Needler::Needler(const Vector2& _pos) : Entity(_pos, SpriteSheet("Galaga/Assets/needler.png", IVector2(19, 25)))
{
	maxSpeed = 100;
	speed = maxSpeed;
	vel = Vector2(speed, 0);
}

Needler::~Needler()
{

}

void Needler::Move()
{
	prevPos = pos;
	pos += vel * Engine::GetDeltaTime();

	Vector4 bounds = Camera::GetVisibleBounds();
	int code = Vector2::Constrain(&pos, bounds.x, bounds.z, bounds.y, bounds.w);

	if (code != -1)
	{
		vel *= -1;
	}
}

void Needler::Render() const
{
	spriteSheet.RenderRelativeTo(pos, currentSprite);
}

void Needler::DebugPhysics() const
{
	DebugPhysicsDefault();
}