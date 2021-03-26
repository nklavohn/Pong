#ifndef ENGINE_PARTICLE
#define ENGINE_PARTICLE

#include "Entity.h"
#include "Engine/Components/RegistryMember.h"
#include "Engine/Components/PhysicsObject.h"

class Particle : public Entity, public PhysicsObject
{
public:
	Particle(std::unique_ptr<Hitbox> _hitbox);
	virtual ~Particle();

	virtual void Update() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

	void Decay();

	virtual std::shared_ptr<Entity> CloneEntity() const override = 0;
	virtual std::shared_ptr<Particle> CloneParticle() const = 0;

protected:
	float lifeTime;
	float currTime;

private:
	void Initialize();
};

#endif
