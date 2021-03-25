#ifndef ENGINE_PLAYER
#define ENGINE_PLAYER

#include "Entity.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Components/PhysicsObject.h"

class Player : public Entity, public PhysicsObject
{
public:
	Player(std::unique_ptr<Hitbox> _hitbox);
	virtual ~Player();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;

	virtual std::shared_ptr<Entity> CloneEntity() const override = 0;
	virtual std::shared_ptr<Player> ClonePlayer() const = 0;
};

#endif
