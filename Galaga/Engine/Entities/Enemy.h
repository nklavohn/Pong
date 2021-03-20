#ifndef ENGINE_ENEMY
#define ENGINE_ENEMY

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(const SpriteSheet sheet);
	~Enemy();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

};

#endif
