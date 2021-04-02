#ifndef SPACEGAME_SPACESHIP
#define SPACEGAME_SPACESHIP

#include "Engine/Entities/Player.h"
#include "Engine/Components/ConstantParticleEmitter.h"
#include "Engine/Physics/RotationalState.h"
#include "Engine/Components/InputProjectileEmitter.h"
#include "Galaga/Entities/Particles/ExhaustParticle.h"
#include "Engine/IO/Keyboard.h"

#include <memory>

class Spaceship : public Player
{

public:
	//constructors
	Spaceship();

	//rule of three
	~Spaceship();
	Spaceship(const Spaceship& other) : Spaceship() {};
	Spaceship& operator=(const Spaceship& other) { return *this; };

	void Update() override;
	void Render() const override;
	void DebugPhysics() const override;
	Vector2 GetPos() const;

	std::shared_ptr<Entity> CloneEntity() const override { std::cout << "Should not be cloning the Spaceship!!" << std::endl; return std::make_shared<Spaceship>(*this); }
	std::shared_ptr<Player> ClonePlayer() const override { std::cout << "Should not be cloning the Spaceship!!" << std::endl; return std::make_shared<Spaceship>(*this); }
	
private:
	int numOfLives = 3;

	//physics and movement things
	float speed;
	float rotSpeed;
	Vector2 velDir;
	RotationalState rState = RotationalState(0, 0, 1, false, 0);

	//emitters
	ConstantParticleEmitter exhaust;
	std::unique_ptr<InputProjectileEmitter> weapon;

	void Move();
	void Shoot();
};

class PhotoCannon : public InputProjectileEmitter
{
public:
	PhotoCannon(std::unique_ptr<Projectile> _projectile, const float& _cooldown) : InputProjectileEmitter(std::move(_projectile), _cooldown) {};
	bool Input() const override
	{
		return Keyboard::IsKeyPressed(Keyboard::SPACE);
	}
};

#endif