#ifndef GALAGA_SPACESHIP
#define GALAGA_SPACESHIP

#include "Engine/Graphics/Sprite.h"
#include "Engine/Math/Vector.h"

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
	Vector pos;
	Vector posMins;
	Vector posMaxs;

	float speed;

	Sprite sprite;

	int numOfLives;

	float shotCooldownMax;
	float shotCooldown;
};

#endif