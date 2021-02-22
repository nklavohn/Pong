#ifndef ENGINE_HITCIRCLE
#define ENGINE_HITCIRCLE

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"

class Hitcircle
{
public:
	Hitcircle();
	Hitcircle(float cx, float cy, float _r);
	Hitcircle(Vector2 _center, float _r);
	~Hitcircle();

	bool IsPointInside(Vector2& pos, bool inclusive = false);
	bool DoesBoxOverlap(const Vector4& _box, bool inclusive = false);

	void SetRadius(const float& _r);
	void SetCenter(const Vector2& _center);
	void AddToCenter(const Vector2& delta);

	void Render(const Color& c);

	Vector2 GetCenter();
	Vector4 GetRadius();

private:
	Vector2 center;
	float r;

	void Initialize(const float& cx, const float& cy, const float& _r);
};

#endif