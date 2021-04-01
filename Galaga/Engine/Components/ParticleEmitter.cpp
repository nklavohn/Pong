#include "ParticleEmitter.h"

#include <chrono>

ParticleEmitter::ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown) : Emitter(_cooldown), particle(std::move(_particle))
{

}

ParticleEmitter::ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, 
	const std::shared_ptr<EntityQueue<Entity>> sQueue)
		: Emitter(_cooldown, sQueue), particle(std::move(_particle))
{

}

ParticleEmitter::~ParticleEmitter()
{

}

void ParticleEmitter::SetParticle(std::unique_ptr<Particle> _particle)
{
	particle = std::move(_particle);
}