#include "Hitcircle.h"

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

bool Hitcircle::IsPointInside(Vector2& pos, bool inclusive = false)
{
	if (inclusive)
		return Vector2::Dist2Between(center, pos) <= r * r;
	return Vector2::Dist2Between(center, pos) < r * r;
}

bool Hitcircle::DoesBoxOverlap(const Vector4& _box, bool inclusive = false)
{
	//TODO implement does box overlap
}

void Hitcircle::SetRadius(const float& _r)
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

void Hitcircle::Render(const Color& c)
{
	//TODO implement hitcircle rendering and ShapeRenderer for cirlces
}

Vector2 Hitcircle::GetCenter()
{
	return center;
}

Vector4 Hitcircle::GetRadius()
{
	return r;
}

