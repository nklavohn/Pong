#ifndef ENGINE_EMITTER
#define ENGINE_EMITTER

#include "Spawner.h"
#include "PhysicsObject.h"

#include <memory>
#include <random>

template <class T>
class Emitter : public Spawner
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity... Emitter");
	static_assert(std::is_base_of<PhysicsObject, T>::value, "T must derive from PhysicsObject... Emitter");

	Emitter(std::unique_ptr<T> _t, const float& _cooldown);
	Emitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~Emitter();

	virtual void Emit(const Vector2& pos, const Vector2& vel) = 0;

	Vector2 RandomizeDir(const Vector2& v, const float& angle);

protected:
	std::unique_ptr<T> t;

	float cooldown;
	float remainingTime;

private:
	std::default_random_engine rngEngine;
	std::normal_distribution<float> rngDistribution;

	void Initialize();
};

template <class T>
Emitter<T>::Emitter(std::unique_ptr<T> _t, const float& _cooldown) : t(std::move(_t))
{
	cooldown = _cooldown;
	Initialize();
}

template <class T>
Emitter<T>::Emitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue) : Spawner(sQueue), t(std::move(_t))
{
	cooldown = _cooldown;
	Initialize();
}

template <class T>
Emitter<T>::~Emitter()
{

}

template <class T>
Vector2 Emitter<T>::RandomizeDir(const Vector2& v, const float& maxAngle)
{
	Vector2 vec = Vector2(v);
	return vec.Rotate(rngDistribution(rngEngine) * maxAngle);
}

template <class T>
void Emitter<T>::Initialize()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rngEngine = std::default_random_engine(seed);
	rngDistribution = std::normal_distribution<float>(0, 0.2F);

	remainingTime = cooldown;
}

#endif
