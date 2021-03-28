#include "ParticleEmitter.h"

#include <chrono>

ParticleEmitter::ParticleEmitter()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rngEngine = std::default_random_engine(seed);
	rngDistribution = std::normal_distribution<float>(0, 0.2F);
}

ParticleEmitter::ParticleEmitter(const std::shared_ptr<EntityQueue<Entity>> sQueue) : Spawner(sQueue)
{

}

ParticleEmitter::~ParticleEmitter()
{

}

Vector2 ParticleEmitter::RandomizeDir(const Vector2& v, const float& maxAngle)
{
	Vector2 vec = Vector2(v);
	return vec.Rotate(rngDistribution(rngEngine) * maxAngle);
}