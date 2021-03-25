#include "ExhaustParticle.h"

#include "Engine/Physics/RectHitbox.h"
#include "Engine/Engine.h"

ExhaustParticle::ExhaustParticle() : Particle(std::unique_ptr<Hitbox>(new RectHitbox(Vector2::ZERO, Vector2(10, 10))))
{
	vel = Vector2::ZERO;
	Initialize();
}

ExhaustParticle::ExhaustParticle(const Vector2& _pos, const Vector2& _vel) : Particle(std::unique_ptr<Hitbox>(new RectHitbox(_pos, Vector2(10, 10))))
{
	vel = _vel;
	Initialize();
}

ExhaustParticle::~ExhaustParticle()
{

}

void ExhaustParticle::Initialize()
{
	lifeTime = 2;
	currTime = lifeTime;
}

void ExhaustParticle::Move()
{
	hitbox->AddToCenter(vel * Engine::GetDeltaTime());
}

void ExhaustParticle::Render() const
{
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), currentSprite);
}

void ExhaustParticle::DebugPhysics() const
{
	DebugPhysicsDefault();
}
