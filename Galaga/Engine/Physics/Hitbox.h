#ifndef ENGINE_HITBOX
#define ENGINE_HITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

class Hitbox
{
public:
	Hitbox();
	Hitbox(float cx, float cy, float bx1, float by1, float bx2, float by2);
	Hitbox(Vector2& _center, Vector4& _box);
	~Hitbox();

	bool IsPointInside(Vector2& pos, bool inclusive);
	bool DoesBoxOverlap(Vector4& _box, bool inclusive);

	void SetHitbox(Vector4& _box);
	void SetCenter(Vector2& _center);
	void AddToCenter(Vector2& delta);

	void Render();

	Vector2 GetCenter();
	Vector4 GetBox();

private:
	Vector4 box;  // (x,y) is bottom left and (z, w) is top right
	Vector2 center;

	void Initialize(float cx, float cy, float bx1, float by1, float bx2, float by2);
};

#endif