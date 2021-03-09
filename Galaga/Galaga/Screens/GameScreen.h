#ifndef GALAGA_GAMESCREEN
#define GALAGA_GAMESCREEN

#include "Engine/Graphics/Screen.h"
#include "Galaga/Entities/Spaceship.h"
#include "Galaga/Entities/Needler.h"
#include "Engine/Physics/EntityPool.h"

class GameScreen: public Screen {

public:
	void Update() override;
	void Render() const override;
	Screen* Clone() const override;

	GameScreen(const IVector2& _dim);
	~GameScreen();

private:
	EntityPool enemies;
	EntityPool projectiles;
	EntityPool particles;
	Spaceship ship = Spaceship(Vector2::ZERO);
};

#endif