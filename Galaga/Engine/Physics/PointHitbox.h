#ifndef ENGINE_POINTHITBOX
#define ENGINE_POINTHITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"

class PointHitbox : public CollisionDetector
{
public:
	PointHitbox();
	PointHitbox(float cx, float cy);
	PointHitbox(Vector2 _center);
	~PointHitbox();

	bool IsPointInside(const Vector2& p) const override;
	bool IsAnyPointInside(const std::vector<Vector2>& ps) const override;
	bool AreAllPointsInside(const std::vector<Vector2>& ps) const override;
	bool DoesLineIntersect(const Vector4& line) const override;
	bool IsCollidingWith(CollisionDetector* cDetector) const override;

	void SetCenter(const Vector2& _center) override;
	void AddToCenter(const Vector2& delta) override;

	void Render(const Color& c) const override;

	Vector2 GetCenter() const;

private:
	Vector2 center;
};

#endif