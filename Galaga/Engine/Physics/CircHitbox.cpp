#include "CircHitbox.h"

#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Math/Camera.h"
#include "RectHitbox.h"
#include "PointHitbox.h"
#include "CollisionDetectorHelper.h"

CircHitbox::CircHitbox()
{
	Initialize(0, 0, 0);
}

CircHitbox::CircHitbox(float cx, float cy, float _r)
{
	Initialize(cx, cy, _r);
}

CircHitbox::CircHitbox(Vector2 _center, float _r)
{
	Initialize(_center.x, _center.y, _r);
}

CircHitbox::~CircHitbox()
{

}

void CircHitbox::Initialize(float cx, float cy, float _r)
{
	center = Vector2(cx, cy);
	r = _r;
}

bool CircHitbox::IsPointInside(const Vector2& pos) const
{
	return Vector2::Dist2Between(center, pos) <= r * r;
}


bool CircHitbox::IsAnyPointInside(const std::vector<Vector2>& ps) const
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

bool CircHitbox::AreAllPointsInside(const std::vector<Vector2>& ps) const
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

bool CircHitbox::DoesLineIntersect(const Vector4& line) const
{
	Vector2 p1 = line.p1();
	Vector2 p2 = line.p2();
	Vector2 p1ToC = center - p1;
	Vector2 p1ToP2 = p2 - p1;
	Vector2 proj = p1ToC.ProjOnto(p1ToP2, false);
	Vector2 radial = proj - p1ToC;

	/*ShapeRenderer::DrawVector(Color::RED, p1, p1 + p1ToP2);
	ShapeRenderer::DrawVector(Color::ORANGE, p1, p1 + p1ToC);
	ShapeRenderer::DrawVector(Color::GREEN, p1, p1 + proj);
	ShapeRenderer::DrawVector(Color::CYAN, p1 + p1ToC, p1 + p1ToC + radial);*/

	return (radial.Len2() <= r * r) && (proj.Dot(p1ToP2) > 0) && (proj.Len2() <= p1ToP2.Len2());
}


bool CircHitbox::IsCollidingWith(CollisionDetector* cDetector) const
{
	CircHitbox* circ = dynamic_cast <CircHitbox*> (cDetector);
	if (circ)
		return CollisionDetectorHelper::CircWithCirc(this, circ);

	RectHitbox* rect = dynamic_cast <RectHitbox*> (cDetector);
	if (rect)
		return CollisionDetectorHelper::RectWithCirc(rect, this);

	PointHitbox* point = dynamic_cast <PointHitbox*> (cDetector);
	if (point)
		return CollisionDetectorHelper::CircWithPoint(this, point);
}

void CircHitbox::SetRadius(float _r)
{
	r = _r;
}

void CircHitbox::SetCenter(const Vector2& _center)
{
	center = _center;
}

void CircHitbox::AddToCenter(const Vector2& delta)
{
	center += delta;
}

void CircHitbox::Render(const Color& c) const
{
	ShapeRenderer::StrokeCircle(c, center, r);
}

Vector2 CircHitbox::GetCenter() const
{
	return center;
}

float CircHitbox::GetRadius() const
{
	return r;
}

