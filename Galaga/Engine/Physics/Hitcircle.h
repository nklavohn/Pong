#ifndef ENGINE_HITCIRCLE
#define ENGINE_HITCIRCLE

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"

class Hitcircle : public CollisionDetector
{
public:
	Hitcircle();
	Hitcircle(float cx, float cy, float _r);
	Hitcircle(Vector2 _center, float _r);
	~Hitcircle();

	bool IsPointInside(const Vector2& p) const;
	bool AreAllPointsInside(const vector<Vector2>& ps) const;
	bool DoesLineIntersect(const Vector4& line) const;
	bool IsCollidingWith(CollisionDetector* cDetector) const;

	void SetRadius(float _r);
	void SetCenter(const Vector2& _center);
	void AddToCenter(const Vector2& delta);

	void Render(const Color& c) const;

	Vector2 GetCenter();
	float GetRadius();

private:
	Vector2 center;
	float r;

	void Initialize(const float& cx, const float& cy, const float& _r);
};

#endif