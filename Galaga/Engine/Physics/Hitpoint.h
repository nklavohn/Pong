#ifndef ENGINE_HITBOX
#define ENGINE_HITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"
#include "Hitcircle.h"

class Hitpoint : public CollisionDetector
{
public:
	Hitpoint();
	Hitpoint(float cx, float cy);
	Hitpoint(Vector2 _center);
	~Hitpoint();

	bool IsPointInside(const Vector2& p) const override;
	bool AreAllPointsInside(const vector<Vector2>& ps) const override;
	bool DoesLineIntersect(const Vector4& line) const override;
	bool IsCollidingWith(CollisionDetector* cDetector) const override;

	void SetHitpoint(const Vector4& _box);
	void SetCenter(const Vector2& _center) override;
	void AddToCenter(const Vector2& delta) override;

	void Render(const Color& c) const override;

	Vector2 GetCenter() const;

private:
	Vector2 center;
};

#endif