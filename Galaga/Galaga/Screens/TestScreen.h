#ifndef GALAGA_TESTSCREEN
#define GALAGA_TESTSCREEN

#include "Engine/Graphics/Screen.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Math/IVector2.h"

class TestScreen : public Screen
{

public:
	void Update() override;
	void Render() override;
	Screen* Clone() override;

	TestScreen(int w, int h);
	~TestScreen();

private:
	SpriteSheet sprite = SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31));
};


#endif