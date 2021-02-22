#ifndef ENGINE_HITBOX
#define ENGINE_HITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"

class Hitbox
{
public:
	Hitbox();
	Hitbox(float cx, float cy, float width, float height);
	Hitbox(Vector2 _center, Vector2 _dim);
	Hitbox(Vector4 _box);
	~Hitbox();

	bool IsPointInside(const Vector2& pos, bool inclusive = false);
	bool DoesBoxOverlap(const Vector4& _box, bool inclusive = false);

	void SetHitbox(const Vector4& _box);
	void SetCenter(const Vector2& _center);
	void AddToCenter(const Vector2& delta);

	void Render(const Color& c);

	Vector2 GetCenter();
	Vector4 GetBox();
	Vector2 GetDim();

private:
	Vector2 center;
	Vector2 dim;
	Vector4 box;  // (x,y) is bottom left and (z, w) is top right
};

#endif