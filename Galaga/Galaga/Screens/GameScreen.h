#ifndef GALAGA_GAMESCREEN
#define GALAGA_GAMESCREEN

#include "Engine/Graphics/Screen.h"
#include "Galaga/Entities/Spaceship.h"

class GameScreen: public Screen {

public:
	void Update() override;
	void Render() override;
	Screen* Clone() override;

	GameScreen(int w, int h);
	~GameScreen();

private:
	Spaceship ship;

};

#endif