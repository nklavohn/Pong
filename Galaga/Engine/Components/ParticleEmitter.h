#ifndef ENGINE_PARTICLEEMITTER
#define ENGINE_PARTICLEEMITTER

#include "Spawner.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Entities/Particle.h"

#include <random>

class ParticleEmitter : public Spawner
{
public:
	ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown);
	ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ParticleEmitter();

	virtual void EmitParticles(const Vector2& pos, const Vector2& vel) = 0;

	Vector2 RandomizeDir(const Vector2& v, const float& angle);

protected:
	std::unique_ptr<Particle> particle;

	float cooldown;
	float remainingTime;

private:
	std::default_random_engine rngEngine;
	std::normal_distribution<float> rngDistribution;

	void Initialize();
};

#endif
