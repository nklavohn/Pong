#include "InputParticleEmitter.h"

#include "Engine/Engine.h"

InputParticleEmitter::InputParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown)
	: ParticleEmitter(std::move(_particle), _cooldown)
{

}

InputParticleEmitter::InputParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown,
	const std::shared_ptr<EntityQueue<Entity>> sQueue)
		: ParticleEmitter(std::move(_particle), _cooldown, sQueue)
{

}

InputParticleEmitter::~InputParticleEmitter()
{

}

void InputParticleEmitter::EmitParticles(const Vector2& pos, const Vector2& vel)
{
	remainingTime -= Engine::GetDeltaTime();

	if (Input() && remainingTime < 0)
	{
		std::shared_ptr<Particle> newPart = particle->CloneParticle();
		newPart->SetPos(pos);
		newPart->SetVel(RandomizeDir(vel, 10));
		spawnQueue->Add(newPart);
		remainingTime = cooldown;
	}
}