#ifndef ENGINE_INPUTPARTICLEEMITTER
#define ENGINE_INPUTPARTICLEEMITTER

#include "ParticleEmitter.h"
#include "Engine/Entities/Particle.h"

#include <memory>

class InputParticleEmitter : public ParticleEmitter
{
public:
	InputParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown);
	InputParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~InputParticleEmitter();

	virtual bool Input() const = 0;
	void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) override;
};

#endif