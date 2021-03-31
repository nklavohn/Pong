#include "ConstantParticleEmitter.h"

#include "Engine/Engine.h"

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown) 
	: ParticleEmitter(std::move(_particle), _cooldown)
{
	
}

ConstantParticleEmitter::ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, 
	const std::shared_ptr<EntityQueue<Entity>> sQueue) 
		: ParticleEmitter(std::move(_particle), _cooldown, sQueue)
{

}

ConstantParticleEmitter::~ConstantParticleEmitter()
{

}

void ConstantParticleEmitter::EmitParticles(const Vector2& pos, const Vector2& vel)
{
	remainingTime -= Engine::GetDeltaTime();

	if (remainingTime < 0)
	{
		std::shared_ptr<Particle> newPart = particle->CloneParticle();
		newPart->SetPos(pos);
		newPart->SetVel(RandomizeDir(vel, 10));
		spawnQueue->Add(newPart);
		remainingTime += cooldown;
	}
}