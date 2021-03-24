#include "ConstantParticleEmitter.h"

#include "Engine/Engine.h"

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown) : particle(std::move(_particle))
{
	cooldown = _cooldown;
	timeRemaining = cooldown;
}

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, 
												 const float& _cooldown, 
												 const std::shared_ptr<entity_queue<Entity>> sQueue) 
	: particle(std::move(_particle)), ParticleEmitter(sQueue)
{
	cooldown = _cooldown;
	timeRemaining = cooldown;
}

ConstantParticleEmitter::~ConstantParticleEmitter()
{

}

void ConstantParticleEmitter::EmitParticles()
{
	timeRemaining -= Engine::GetDeltaTime();

	if (timeRemaining < 0)
	{
		spawnQueue->Add(particle->cloneToShared());
		timeRemaining += cooldown;
	}
}