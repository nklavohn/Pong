#ifndef ENGINE_PARTICLE
#define ENGINE_PARTICLE

#include "Entity.h"
#include "Engine/Physics/CollisionDetector.h"

class Particle : public Entity
{
public:
	Particle();
	Particle(const SpriteSheet sheet);
	~Particle();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

protected:
	float lifeTime;
	float currTime;

	void TickForwards();

private:
	void Initialize();
};

#endif
