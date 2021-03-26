#ifndef ENGINE_ENEMY
#define ENGINE_ENEMY

#include "Entity.h"
#include "Engine/Components/PhysicsObject.h"

class Enemy : public Entity, public PhysicsObject
{
public:
	Enemy(std::unique_ptr<Hitbox> _hitbox);
	virtual ~Enemy();

	virtual void Update() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

	virtual std::shared_ptr<Entity> CloneEntity() const override = 0;
	virtual std::shared_ptr<Enemy> CloneEnemy() const = 0;
};

#endif
