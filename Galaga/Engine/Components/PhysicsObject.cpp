#include "PhysicsObject.h"

#include "Engine/Graphics/ShapeRenderer.h"

PhysicsObject::PhysicsObject(std::unique_ptr<Hitbox> _hitbox) : HitboxedObject(std::move(_hitbox))
{
	prevPos = Vector2::ZERO;
	vel = Vector2::ZERO;
	accel = Vector2::ZERO;
	speed = 0;
	maxSpeed = 0;
}

PhysicsObject::~PhysicsObject()
{

}

void PhysicsObject::SetPos(const Vector2& _pos)
{
	hitbox->SetCenter(_pos);
}

void PhysicsObject::SetVel(const Vector2& _vel)
{
	vel = _vel;
}

void PhysicsObject::SetAccel(const Vector2& _accel)
{
	accel = _accel;
}

void PhysicsObject::DebugPhysicsDefault() const
{
	Vector2 pos = hitbox->GetCenter();
	if (hitbox) hitbox->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::BLUE, pos, pos + vel);
	ShapeRenderer::DrawVector(Color::MAGENTA, pos, pos + accel);
}