#include "Emitter.h"

#include <chrono>

Emitter::Emitter(const float& _cooldown)
{
	Initialize(_cooldown);
}

Emitter::Emitter(const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue) : Spawner(sQueue)
{
	Initialize(_cooldown);
}

Emitter::~Emitter()
{

}

void Emitter::Initialize(const float& _cooldown)
{
	cooldown = _cooldown;
	remainingTime = cooldown;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rngEngine = std::default_random_engine(seed);
	rngDistribution = std::normal_distribution<float>(0, 0.2F);
}

Vector2 Emitter::RandomizeDir(const Vector2& v, const float& maxAngle)
{
	Vector2 vec = Vector2(v);
	return vec.Rotate(rngDistribution(rngEngine) * maxAngle);
}

void Emitter::SetCooldown(const float& _cooldown)
{
	remainingTime += _cooldown - cooldown;
	cooldown = _cooldown;
}