#ifndef GALAGA_TESTSCREEN
#define GALAGA_TESTSCREEN

#include "Engine/Graphics/Screen.h"
#include "Engine/Graphics/Sprite.h"

class TestScreen: public Screen {

public:
	void Update() override;
	void Render() override;
	Screen* Clone() override;

	TestScreen(int w, int h);
	~TestScreen();

	Sprite sprite;
};


#endif