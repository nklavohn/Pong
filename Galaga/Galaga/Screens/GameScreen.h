#ifndef SPACEGAME_GAMESCREEN
#define SPACEGAME_GAMESCREEN

#include "Engine/Graphics/Screen.h"
#include "Galaga/Entities/Spaceship.h"
#include "Galaga/Entities/Needler.h"
#include "Engine/Entities/EntityPool.h"
#include "Engine/Entities/Particle.h"

class GameScreen: public Screen {

public:
	void Update() override;
	void Render() const override;
	Screen* Clone() const override;

	GameScreen(const IVector2& _dim);
	~GameScreen();

private:
	
};

#endif