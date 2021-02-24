#include "Hitcircle.h"
#include "Hitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"

Hitcircle::Hitcircle()
{
	Initialize(0, 0, 0);
}

Hitcircle::Hitcircle(float cx, float cy, float _r)
{
	Initialize(cx, cy, _r);
}

Hitcircle::Hitcircle(Vector2 _center, float _r)
{
	Initialize(_center.x, _center.y, _r);
}

Hitcircle::~Hitcircle()
{

}

void Hitcircle::Initialize(const float& cx, const float& cy, const float& _r)
{
	center = Vector2(cx, cy);
	r = _r;
}

bool Hitcircle::IsPointInside(const Vector2& pos) const
{
	return Vector2::Dist2Between(center, pos) <= r * r;
}

bool Hitcircle::AreAllPointsInside(const vector<Vector2>& ps) const
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

bool Hitcircle::DoesLineIntersect(const Vector4& line) const
{
	Vector2 p1 = line.p1();
	Vector2 p2 = line.p2();
	Vector2 p1ToC = center - p1;
	Vector2 p1ToP2 = p2 - p1;
	Vector2 proj = p1ToC.ProjOnto(p1ToP2);
	Vector2 radial = proj - p1ToC;
	return (radial.Len2() <= r * r) && (proj.Dot(p1ToP2) > 0);
}


bool Hitcircle::IsCollidingWith(CollisionDetector* cDetector) const
{
	Hitcircle* hitcircle = dynamic_cast <Hitcircle*> (cDetector);
	if (hitcircle)
	{
		Vector2 cToC = center - hitcircle->center;
		float bigR = r + hitcircle->r;
		return cToC.Len2() <= bigR * bigR;
	}

	Hitbox* hitbox = dynamic_cast <Hitbox*> (cDetector);
	if (hitbox)
	{
		Vector2 rectCenter = hitbox->GetCenter();
		float rectDiagonal = hitbox->GetDim().Len2() / 4;
		if (Vector2::DistBetween(center, rectCenter) > r + rectDiagonal)
			return false;

		vector<Vector4> sides = hitbox->GetSides();

		return (hitbox->IsPointInside(center) ||
			DoesLineIntersect(sides[0]) ||
			DoesLineIntersect(sides[1]) ||
			DoesLineIntersect(sides[2]) ||
			DoesLineIntersect(sides[3]) ||
			AreAllPointsInside(hitbox->GetVertices())
			);
	}
}

void Hitcircle::SetRadius(float _r)
{
	r = _r;
}

void Hitcircle::SetCenter(const Vector2& _center)
{
	center = _center;
}

void Hitcircle::AddToCenter(const Vector2& delta)
{
	center += delta;
}

void Hitcircle::Render(const Color& c) const
{
	ShapeRenderer::StrokeCircle(c, center, r);
}

Vector2 Hitcircle::GetCenter()
{
	return center;
}

float Hitcircle::GetRadius()
{
	return r;
}

