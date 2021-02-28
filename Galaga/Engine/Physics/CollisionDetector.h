#ifndef ENGINE_COLLISIONDETECTOR
#define ENGINE_COLLISIONDETECTOR

#include "Engine/Graphics/Color.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

#include <vector>

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();

	virtual bool IsPointInside(const Vector2& p) const = 0;
	virtual bool IsAnyPointInside(const std::vector<Vector2>& ps) const = 0;
	virtual bool AreAllPointsInside(const std::vector<Vector2>& ps) const = 0;
	virtual bool DoesLineIntersect(const Vector4& line) const = 0;
	virtual bool IsCollidingWith(CollisionDetector* cDetector) const = 0;

	virtual void SetCenter(const Vector2& _center) = 0;
	virtual void AddToCenter(const Vector2& delta) = 0;

	virtual void Render(const Color& c) const = 0;

};

#endif