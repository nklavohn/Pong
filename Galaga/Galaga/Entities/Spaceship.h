#ifndef GALAGA_SPACESHIP
#define GALAGA_SPACESHIP

#include "Engine/Graphics/Spritesheet.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/IVector2.h"

class Spaceship
{

public:
	Spaceship();
	~Spaceship();

	void Move();
	void Shoot();
	bool IsHit();
	void Respawn();
	void Render();

private:
	Vector2 pos = Vector2(30, 30);
	Vector2 posMins = Vector2(15, 15);
	Vector2 posMaxs = Vector2(15, 15);

	float speed = 100;

	SpriteSheet sprite = SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31));

	int numOfLives = 3;

	float shotCooldownMax = 0.5;
	float shotCooldown = 0;

	const IVector2 LEFT = IVector2(0, 0);
	const IVector2 STRAIGHT = IVector2(1, 0);
	const IVector2 RIGHT = IVector2(2, 0);

	Vector2 dir = Vector2::ZERO;
};

#endif