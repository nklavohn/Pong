#ifndef ENGINE_EMITTER
#define ENGINE_EMITTER

#include "Spawner.h"

#include <random>

class Emitter : public Spawner
{
public:
	Emitter(const float& _cooldown);
	Emitter(const float& _cooldown, std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~Emitter();

	virtual void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) = 0;
	Vector2 RandomizeDir(const Vector2& vel, const float& angleRange);
	void SetCooldown(const float& _cooldown);

protected:
	float cooldown;
	float remainingTime;

	std::default_random_engine rngEngine;
	std::normal_distribution<float> rngDistribution;

private:
	void Initialize(const float& _cooldown);
};

#endif
