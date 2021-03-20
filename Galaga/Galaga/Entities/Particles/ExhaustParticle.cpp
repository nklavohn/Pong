#include "ExhaustParticle.h"

#include "Engine/Physics/RectHitbox.h"
#include "Engine/Engine.h"

ExhaustParticle::ExhaustParticle() : Particle(SpriteSheet("Galaga/Assets/exhaust.png", IVector2(10, 20)))
{
	Initialize();
}

ExhaustParticle::ExhaustParticle(const Vector2& _pos, const Vector2& _vel) : Particle(SpriteSheet("Galaga/Assets/exhaust.png", IVector2(10, 20)))
{
	hitbox = new RectHitbox(_pos, Vector2(10, 10));
	vel = _vel;
	Initialize();
}

ExhaustParticle::~ExhaustParticle()
{

}

void ExhaustParticle::Initialize()
{
	lifeTime = 3;
	currTime = lifeTime;
}

void ExhaustParticle::Move()
{
	hitbox->AddToCenter(vel * Engine::GetDeltaTime());
	TickForwards();
}

void ExhaustParticle::Render() const
{
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), currentSprite);
}

void ExhaustParticle::DebugPhysics() const
{
	DebugPhysicsDefault();
}
