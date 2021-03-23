#ifndef SPACEGAME_TESTSCREEN
#define SPACEGAME_TESTSCREEN

#include "Engine/Graphics/Screen.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Physics/RectHitbox.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Physics/PointHitbox.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Galaga/Entities/Spaceship.h"

class TestScreen : public Screen
{

public:
	void Update() override;
	void Render() const override;
	Screen* Clone() const override;

	TestScreen(const IVector2& _dim);
	~TestScreen();

private:
	/*RectHitbox box1 = RectHitbox(Vector2(0, 00), Vector2(25, 25));
	RectHitbox box2 = RectHitbox(Vector2(30, 30), Vector2(10, 20));
	CircHitbox circ1 = CircHitbox(Vector2(0, 50), 10);
	CircHitbox circ2 = CircHitbox(Vector2(-50, 0), 10);
	PointHitbox point1 = PointHitbox(Vector2(-20, -20));*/

	Spaceship ship = Spaceship();
};


#endif