#ifndef ENGINE_PLAYER
#define ENGINE_PLAYER

#include "Entity.h"
#include "Engine/Graphics/SpriteSheet.h"

class Player : public Entity
{
public:
	Player(const SpriteSheet& _sheet);
	~Player();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;
};

#endif
