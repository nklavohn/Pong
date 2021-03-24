#include "Particle.h"
#include "Engine/Engine.h"

Particle::Particle(std::unique_ptr<Hitbox> _hitbox) : Entity(PARTICLE), PhysicsObject(std::move(_hitbox))
{
	Initialize();
}

Particle::~Particle()
{

}

void Particle::Initialize()
{
	lifeTime = 0;
	currTime = 0;
}

void Particle::Decay()
{
	currTime -= Engine::GetDeltaTime();
	if (currTime < 0)
	{
		FlagForRemoval();
	}
}