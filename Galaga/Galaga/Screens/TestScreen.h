#ifndef GALAGA_TESTSCREEN
#define GALAGA_TESTSCREEN

#include "Engine/Graphics/Screen.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Physics/Hitbox.h"
#include "Engine/Physics/Hitcircle.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

class TestScreen : public Screen
{

public:
	void Update() override;
	void Render() override;
	Screen* Clone() override;

	TestScreen(int w, int h);
	~TestScreen();

private:
	Hitbox box1 = Hitbox(Vector2(50, 50), Vector2(25, 25));
	Hitbox box2 = Hitbox(Vector2(75, 75), Vector2(10, 20));

};


#endif