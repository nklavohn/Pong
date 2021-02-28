#include "Hitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Math/Camera.h"

Hitbox::Hitbox()
{
	center = Vector2::ZERO;
	dim = Vector2::ZERO;
	box = Vector4::ZERO;
}

Hitbox::Hitbox(float cx, float cy, float width, float height)
{
	center = Vector2(cx, cy);
	dim = Vector2(width, height);
	box = Vector4(center - dim / 2, center + dim / 2);
}

Hitbox::Hitbox(Vector2 _center, Vector2 _dim)
{
	center = _center;
	dim = _dim;
	box = Vector4(center - dim / 2, center + dim / 2);
}

Hitbox::Hitbox(Vector4 _box)
{
	center = center = Vector2((_box.x + _box.z) / 2, (_box.y + _box.w) / 2);
	dim = Vector2(std::abs(_box.x - _box.z), std::abs(_box.y - _box.w));
	box = Vector4(center - dim / 2, center + dim / 2);
}

Hitbox::~Hitbox()
{

}

bool Hitbox::IsPointInside(const Vector2& p) const
{
	return (p.x <= box.z) && (p.x >= box.x) && (p.y <= box.w) && (p.y >= box.y);
}

bool Hitbox::AreAllPointsInside(const vector<Vector2>& ps) const
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

bool Hitbox::DoesLineIntersect(const Vector4& line) const
{
	vector<Vector4> sides = GetSides();

	int status = -1;
	for (int i = 0; i < 4; i++)
	{
		Vector4::DoLinesIntersect(line, sides[i], &status);
		if (status == 0)
			return true;
	}

	return AreAllPointsInside(vector<Vector2> { line.p1(), line.p2() });
}

bool Hitbox::IsCollidingWith(CollisionDetector* cDetector) const
{
	Hitbox* hitbox = dynamic_cast <Hitbox*> (cDetector);
	if (hitbox)
	{
		Vector4 rect = hitbox->GetBox();
		return (box.x <= rect.z) && (rect.x <= box.z) && (box.y <= rect.w) && (rect.y <= box.w);
	}

	Hitcircle* hitcircle = dynamic_cast <Hitcircle*> (cDetector);
	if (hitcircle)
	{
		Vector2 cirCenter = hitcircle->GetCenter();
		float cirRadius = hitcircle->GetRadius();
		float thisDiagonal = dim.Len2() / 4;
		if (Vector2::DistBetween(center, cirCenter) > cirRadius + thisDiagonal)
			return false;

		vector<Vector4> sides = GetSides();

		return (IsPointInside(cirCenter) ||
			hitcircle->DoesLineIntersect(sides[0]) ||
			hitcircle->DoesLineIntersect(sides[1]) ||
			hitcircle->DoesLineIntersect(sides[2]) ||
			hitcircle->DoesLineIntersect(sides[3]) ||
			hitcircle->AreAllPointsInside(GetVertices())
			);
	}
}

void Hitbox::SetHitbox(const Vector4& _box)
{
	center = Vector2((_box.x + _box.z) / 2, (_box.y + _box.w) / 2);
	dim = Vector2(std::abs(_box.x - _box.z), std::abs(_box.y - _box.w));

	Vector2 diagonal = dim / 2;
	box = Vector4(center - diagonal, center + diagonal);
}

void Hitbox::SetCenter(const Vector2& _center)
{
	center = _center;
	Vector2 diagonal = dim / 2;
	box = Vector4(center - diagonal, center + diagonal);
}

void Hitbox::AddToCenter(const Vector2& delta)
{
	center += delta;
	box = box.Add(delta.x, delta.y, delta.x, delta.y);
}

Vector2 Hitbox::GetCenter() const
{
	return center;
}

Vector4 Hitbox::GetBox() const
{
	return box;
}

void Hitbox::Render(const Color& c) const
{
	Vector4 displayPos = Camera::ToDisplayCoords(box, Camera::F_METER_TO_PIXELS);
	ShapeRenderer::StrokeBox(c, displayPos);
}

Vector2 Hitbox::GetDim() const
{
	return dim;
}

vector<Vector4> Hitbox::GetSides() const
{
	return vector<Vector4> { Vector4(box.x, box.y, box.x, box.w),
		Vector4(box.x, box.w, box.z, box.w),
		Vector4(box.z, box.w, box.z, box.y),
		Vector4(box.z, box.y, box.x, box.y) };
}

vector<Vector2> Hitbox::GetVertices() const
{
	return vector<Vector2> { Vector2(box.x, box.y),
		Vector2(box.x, box.w),
		Vector2(box.z, box.w),
		Vector2(box.z, box.y) };
}