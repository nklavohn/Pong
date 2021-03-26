#include "ConstantParticleEmitter.h"

#include "Engine/Engine.h"

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown) : particle(std::move(_particle))
{
	cooldown = _cooldown;
	timeRemaining = cooldown;
}

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, 
												 const float& _cooldown, 
												 const std::shared_ptr<EntityQueue<Entity>> sQueue) 
	: particle(std::move(_particle)), ParticleEmitter(sQueue)
{
	cooldown = _cooldown;
	timeRemaining = cooldown;
}

ConstantParticleEmitter::~ConstantParticleEmitter()
{

}

void ConstantParticleEmitter::EmitParticles(const Vector2& pos, const Vector2& vel)
{
	timeRemaining -= Engine::GetDeltaTime();

	if (timeRemaining < 0)
	{
		std::shared_ptr<Particle> newPart = particle->CloneParticle();
		newPart->SetPos(pos);
		newPart->SetVel(vel);
		spawnQueue->Add(newPart);
		timeRemaining += cooldown;
	}
}