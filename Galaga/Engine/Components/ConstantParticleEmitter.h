#ifndef ENGINE_CONSTANTPARTICLEEMITTER
#define ENGINE_CONSTANTPARTICLEEMITTER

#include "ParticleEmitter.h"
#include "Engine/Entities/Particle.h"

class ConstantParticleEmitter : public ParticleEmitter
{
public:
	ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown);
	ConstantParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ConstantParticleEmitter();

	void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) override;

};

#endif