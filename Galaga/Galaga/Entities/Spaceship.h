#ifndef GALAGA_SPACESHIP
#define GALAGA_SPACESHIP

#include "Engine/Graphics/Spritesheet.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Physics/Entity.h"

class Spaceship : public Entity
{

public:
	Spaceship();
	~Spaceship();

	void Move() override;
	void Shoot();
	bool IsHit();
	void Respawn();
	void Render() const override;
	void DebugPhysics() const override;
	Vector2 GetPos() const;

private:
	int numOfLives = 3;

	float shotCooldownMax = 0.5;
	float shotCooldown = 0;

	Vector2 vel = Vector2::ZERO;

	const IVector2 LEFT = IVector2(0, 0);
	const IVector2 STRAIGHT = IVector2(1, 0);
	const IVector2 RIGHT = IVector2(2, 0);
};

#endif