#ifndef ENGINE_CONSTANTPARTICLEEMITTER
#define ENGINE_CONSTANTPARTICLEEMITTER

#include "ParticleEmitter.h"
#include "Engine/Entities/Particle.h"

class ConstantParticleEmitter : public ParticleEmitter
{
public:
	ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown);
	ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, const std::shared_ptr<entity_queue<Entity>> sQueue);
	~ConstantParticleEmitter();

	void EmitParticles() override;

private:
	float cooldown;
	float timeRemaining;
	std::unique_ptr<Particle> particle;
};

#endif