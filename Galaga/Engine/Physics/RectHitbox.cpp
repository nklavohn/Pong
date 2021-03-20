#include "RectHitbox.h"

#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Math/Camera.h"
#include "CircHitbox.h"
#include "HitboxHelper.h"

RectHitbox::RectHitbox()
{
	center = Vector2::ZERO;
	dim = Vector2::ZERO;
	box = Vector4::ZERO;
}

RectHitbox::RectHitbox(float cx, float cy, float width, float height)
{
	center = Vector2(cx, cy);
	dim = Vector2(width, height);
	box = Vector4(center - dim / 2, center + dim / 2);
}

RectHitbox::RectHitbox(Vector2 _center, Vector2 _dim)
{
	center = _center;
	dim = _dim;
	box = Vector4(center - dim / 2, center + dim / 2);
}

RectHitbox::RectHitbox(Vector4 _box)
{
	center = center = Vector2((_box.x + _box.z) / 2, (_box.y + _box.w) / 2);
	dim = Vector2(std::abs(_box.x - _box.z), std::abs(_box.y - _box.w));
	box = Vector4(center - dim / 2, center + dim / 2);
}

RectHitbox::~RectHitbox()
{

}

bool RectHitbox::IsPointInside(const Vector2& p) const
{
	return (p.x <= box.z) && (p.x >= box.x) && (p.y <= box.w) && (p.y >= box.y);
}

bool RectHitbox::IsAnyPointInside(const std::vector<Vector2>& ps) const
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

bool RectHitbox::AreAllPointsInside(const std::vector<Vector2>& ps) const
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

bool RectHitbox::DoesLineIntersect(const Vector4& line) const
{
	std::vector<Vector4> sides = GetSides();

	int status = -1;
	for (int i = 0; i < 4; i++)
	{
		Vector4::DoLinesIntersect(line, sides[i], &status);
		if (status == 0)
			return true;
	}

	return AreAllPointsInside(std::vector<Vector2> { line.p1(), line.p2() });
}

bool RectHitbox::IsCollidingWith(Hitbox* cDetector) const
{
	RectHitbox* rect = dynamic_cast <RectHitbox*> (cDetector);
	if (rect)
		return HitboxHelper::RectWithRect(this, rect);

	CircHitbox* circ = dynamic_cast <CircHitbox*> (cDetector);
	if (circ)
		return HitboxHelper::RectWithCirc(this, circ);

	PointHitbox* point = dynamic_cast <PointHitbox*> (cDetector);
	if (point)
		return HitboxHelper::RectWithPoint(this, point);
}

void RectHitbox::SetHitbox(const Vector4& _box)
{
	center = Vector2((_box.x + _box.z) / 2, (_box.y + _box.w) / 2);
	dim = Vector2(std::abs(_box.x - _box.z), std::abs(_box.y - _box.w));

	Vector2 diagonal = dim / 2;
	box = Vector4(center - diagonal, center + diagonal);
}

void RectHitbox::SetCenter(const Vector2& _center)
{
	center = _center;
	Vector2 diagonal = dim / 2;
	box = Vector4(center - diagonal, center + diagonal);
}

void RectHitbox::AddToCenter(const Vector2& delta)
{
	center += delta;
	box = box.Add(delta.x, delta.y, delta.x, delta.y);
}

Vector2 RectHitbox::GetCenter() const
{
	return center;
}

Vector4 RectHitbox::GetBox() const
{
	return box;
}

void RectHitbox::Render(const Color& c) const
{
	ShapeRenderer::StrokeBox(c, box);
}

Vector2 RectHitbox::GetDim() const
{
	return dim;
}

std::vector<Vector4> RectHitbox::GetSides() const
{
	return std::vector<Vector4> { Vector4(box.x, box.y, box.x, box.w),
		Vector4(box.x, box.w, box.z, box.w),
		Vector4(box.z, box.w, box.z, box.y),
		Vector4(box.z, box.y, box.x, box.y) };
}

std::vector<Vector2> RectHitbox::GetVertices() const
{
	return std::vector<Vector2> { Vector2(box.x, box.y),
		Vector2(box.x, box.w),
		Vector2(box.z, box.w),
		Vector2(box.z, box.y) };
}