#include "ParticleEmitter.h"

#include <chrono>

ParticleEmitter::ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown) : particle(std::move(_particle))
{
	cooldown = _cooldown;
	Initialize();
}

ParticleEmitter::ParticleEmitter(std::unique_ptr<Particle> _particle, const float& _cooldown, 
	const std::shared_ptr<EntityQueue<Entity>> sQueue)
		: Spawner(sQueue), particle(std::move(_particle))
{
	cooldown = _cooldown;
	Initialize();
}

ParticleEmitter::~ParticleEmitter()
{

}

void ParticleEmitter::Initialize()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rngEngine = std::default_random_engine(seed);
	rngDistribution = std::normal_distribution<float>(0, 0.2F);

	remainingTime = cooldown;
}

Vector2 ParticleEmitter::RandomizeDir(const Vector2& v, const float& maxAngle)
{
	Vector2 vec = Vector2(v);
	return vec.Rotate(rngDistribution(rngEngine) * maxAngle);
}