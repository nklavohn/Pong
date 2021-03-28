#ifndef ENGINE_PARTICLEEMITTER
#define ENGINE_PARTICLEEMITTER

#include "Spawner.h"
#include "Engine/Math/Vector2.h"

#include <random>

class ParticleEmitter : public Spawner
{
public:
	ParticleEmitter();
	ParticleEmitter(const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ParticleEmitter();

	virtual void EmitParticles(const Vector2& pos, const Vector2& vel) = 0;

	Vector2 RandomizeDir(const Vector2& v, const float& angle);

private:
	std::default_random_engine rngEngine;
	std::normal_distribution<float> rngDistribution;
};

#endif
