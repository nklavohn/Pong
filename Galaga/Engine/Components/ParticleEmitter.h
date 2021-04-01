#ifndef ENGINE_PARTICLEEMITTER
#define ENGINE_PARTICLEEMITTER

#include "Emitter.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Entities/Particle.h"

#include <random>

class ParticleEmitter : public Emitter
{
public:
	ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown);
	ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ParticleEmitter();

	virtual void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) override = 0;

	void SetParticle(std::unique_ptr<Particle> _particle);

protected:
	std::unique_ptr<Particle> particle;

};

#endif
