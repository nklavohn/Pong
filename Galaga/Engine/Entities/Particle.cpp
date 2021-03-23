#include "Particle.h"
#include "Engine/Engine.h"

Particle::Particle() : Entity(PARTICLE)
{
	Initialize();
}

Particle::Particle(SpriteSheet sheet) : Entity(PARTICLE, sheet)
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