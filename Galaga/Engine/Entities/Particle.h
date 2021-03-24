#ifndef ENGINE_PARTICLE
#define ENGINE_PARTICLE

#include "Entity.h"
#include "Engine/Components/RegistryMember.h"
#include "Engine/Components/PhysicsObject.h"

class Particle : public Entity, public PhysicsObject
{
public:
	Particle(std::unique_ptr<Hitbox> _hitbox);
	~Particle();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

protected:
	float lifeTime;
	float currTime;

	void Decay();

	virtual Particle* clone_impl() const = 0;

private:
	void Initialize();
};

#endif
