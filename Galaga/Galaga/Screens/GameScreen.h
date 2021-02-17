#ifndef GALAGA_GAMESCREEN
#define GALAGA_GAMESCREEN

#include "Engine/Graphics/Screen.h"

class GameScreen: public Screen {

public:
	void Update() override;
	void Render() override;

	GameScreen(int w, int h);
	~GameScreen();

};

#endif