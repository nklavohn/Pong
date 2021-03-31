#include "ExhaustParticle.h"

#include "Engine/Physics/RectHitbox.h"
#include "Engine/Engine.h"

ExhaustParticle::ExhaustParticle() : Particle(std::unique_ptr<Hitbox>(new RectHitbox(Vector2::ZERO, Vector2(5, 5))))
{
	Initialize();
}

ExhaustParticle::ExhaustParticle(const Vector2& _pos, const Vector2& _vel) : Particle(std::unique_ptr<Hitbox>(new RectHitbox(_pos, Vector2(5, 5))))
{
	tState.pos = _pos;
	tState.vel = _vel;
	Initialize();
}

ExhaustParticle::~ExhaustParticle()
{

}

void ExhaustParticle::Initialize()
{
	lifeTime = 1;
	currTime = lifeTime;
}

void ExhaustParticle::Update()
{
	ApplyPhysics();
}

void ExhaustParticle::Render() const
{
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), currentSprite);
}

void ExhaustParticle::DebugPhysics() const
{
	//DebugPhysicsDefault();
	hitbox->Render(Color(1, 1, 1, currTime));
}
