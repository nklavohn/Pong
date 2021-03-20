#ifndef ENGINE_PROJECTILE
#define ENGINE_PROJECTILE

#include "Entity.h"

class Projectile : public Entity
{
public:
	Projectile();
	Projectile(const SpriteSheet sheet);
	~Projectile();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;
};

#endif
