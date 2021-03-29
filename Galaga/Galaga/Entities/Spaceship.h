#ifndef SPACEGAME_SPACESHIP
#define SPACEGAME_SPACESHIP

#include "Engine/Graphics/Spritesheet.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Entities/Player.h"
#include "Engine/Components/ConstantParticleEmitter.h"
#include "Engine/Components/HitboxedObject.h"
#include "Engine/Physics/RotationalState.h"

class Spaceship : public Player, public ConstantParticleEmitter
{

public:
	//constructors
	Spaceship();

	//rule of three
	~Spaceship();
	Spaceship(const Spaceship& other) : Spaceship() {};
	Spaceship& operator=(const Spaceship& other) { return *this; };

	void Update() override;
	void Shoot();
	bool IsHit();
	void Respawn();
	void Render() const override;
	void DebugPhysics() const override;
	Vector2 GetPos() const;

	std::shared_ptr<Entity> CloneEntity() const override { std::cout << "Should not be cloning the Spaceship!!" << std::endl; return std::make_shared<Spaceship>(*this); }
	std::shared_ptr<Player> ClonePlayer() const override { std::cout << "Should not be cloning the Spaceship!!" << std::endl; return std::make_shared<Spaceship>(*this); }
	
private:
	int numOfLives = 3;

	float shotCooldownMax = 0.5;
	float shotCooldown = 0;

	RotationalState rState = RotationalState(0, 0, 1, false, 0);

	float speed;
	float rotSpeed;
	Vector2 velDir;

	const IVector2 LEFT = IVector2(0, 0);
	const IVector2 STRAIGHT = IVector2(1, 0);
	const IVector2 RIGHT = IVector2(2, 0);
};

#endif