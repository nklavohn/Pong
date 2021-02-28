#include "PointHitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Engine.h"
#include "CircHitbox.h"
#include "RectHitbox.h"
#include "CollisionDetectorHelper.h"

PointHitbox::PointHitbox()
{
	center = Vector2::ZERO;
}

PointHitbox::PointHitbox(float cx, float cy)
{
	center = Vector2(cx, cy);
}

PointHitbox::PointHitbox(Vector2 _center)
{
	center = _center;
}

PointHitbox::~PointHitbox()
{

}

bool PointHitbox::IsPointInside(const Vector2& p) const
{
	return center == p;
}

bool PointHitbox::IsAnyPointInside(const std::vector<Vector2>& ps) const
{
	bool anyInside = false;
	for (auto element = ps.cbegin(); element != ps.cend(); element++)
	{
		anyInside = anyInside || IsPointInside(*element);
		if (anyInside)
			return true;
	}
	return false;
}

bool PointHitbox::AreAllPointsInside(const std::vector<Vector2>& ps) const
{
	bool allInside = true;
	for (auto element = ps.cbegin(); element != ps.cend(); element++)
	{
		allInside = allInside && IsPointInside(*element);
		if (!allInside)
			return false;
	}
	return true;
}

bool PointHitbox::DoesLineIntersect(const Vector4& line) const
{
	Vector4 line1 = Vector4(line.p1(), center);
	Vector4 line2 = Vector4(center, line.p2());
	return (line1.Len() + line2.Len()) == line.Len();
}

bool PointHitbox::IsCollidingWith(CollisionDetector* cDetector) const
{
	CircHitbox* circ = dynamic_cast <CircHitbox*> (cDetector);
	if (circ)
		return CollisionDetectorHelper::CircWithPoint(circ, this);

	RectHitbox* rect = dynamic_cast <RectHitbox*> (cDetector);
	if (rect)
		return CollisionDetectorHelper::RectWithPoint(rect, this);

	PointHitbox* point = dynamic_cast <PointHitbox*> (cDetector);
	if (point)
		return CollisionDetectorHelper::PointWithPoint(this, point);
}

void PointHitbox::SetCenter(const Vector2& _center)
{
	center = _center;
}

void PointHitbox::AddToCenter(const Vector2& delta)
{
	center += delta;
}

void PointHitbox::Render(const Color& c) const
{
	ShapeRenderer::FillCircle(c, center, 3 / Engine::SCALE, 6);
}

Vector2 PointHitbox::GetCenter() const
{
	return center;
}
