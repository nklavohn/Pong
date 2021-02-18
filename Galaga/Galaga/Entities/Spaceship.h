#ifndef GALAGA_SPACESHIP
#define GALAGA_SPACESHIP

#include "Engine/Graphics/Spritesheet.h"
#include "Engine/Math/Vector.h"
#include "Engine/Math/IVector.h"

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
	Vector pos = Vector(30, 30);
	Vector posMins = Vector(15, 15);
	Vector posMaxs = Vector(15, 15);

	float speed = 100;

	SpriteSheet sprite = SpriteSheet("Galaga/Assets/ship.png", IVector(21, 31));

	int numOfLives = 3;

	float shotCooldownMax = 0.5;
	float shotCooldown = 0;

	const IVector LEFT = IVector(0, 0);
	const IVector STRAIGHT = IVector(1, 0);
	const IVector RIGHT = IVector(2, 0);

	Vector dir = Vector::ZERO;
};

#endif