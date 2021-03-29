#include "PhysicsObject.h"

#include "Engine/Graphics/ShapeRenderer.h"

PhysicsObject::PhysicsObject(std::unique_ptr<Hitbox> _hitbox) : HitboxedObject(std::move(_hitbox))
{
	tState = TranslationalState();
}

PhysicsObject::PhysicsObject(std::unique_ptr<Hitbox> _hitbox, const TranslationalState& _tState) : HitboxedObject(std::move(_hitbox))
{
	tState = _tState;
}

PhysicsObject::~PhysicsObject()
{

}

void PhysicsObject::SetPos(const Vector2& _pos)
{
	tState.pos = _pos;
}

void PhysicsObject::SetVel(const Vector2& _vel)
{
	tState.vel = _vel;
}

void PhysicsObject::ApplyPhysics()
{
	tState.Move();
	hitbox->SetCenter(tState.pos);
}

void PhysicsObject::DebugPhysicsDefault() const
{
	hitbox->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::BLUE, tState.pos, tState.pos + tState.vel);
	ShapeRenderer::DrawVector(Color::MAGENTA, tState.pos, tState.pos + tState.accel);
}