#include "Hitbox.h"

Hitbox::Hitbox()
{
	Initialize(0, 0, 0, 0, 0, 0);
}

Hitbox::Hitbox(float cx, float cy, float bx1, float by1, float bx2, float by2)
{
	Initialize(cx, cy, bx1, by1, bx2, by2);
}

Hitbox::Hitbox(Vector2& _center, Vector4& _box)
{
	Initialize(_center.x, _center.y, _box.x, _box.y, _box.z, _box.w);
}

Hitbox::~Hitbox()
{

}

void Hitbox::Initialize(float cx, float cy, float bx1, float by1, float bx2, float by2)
{
	center = Vector2(cx, cy);
	box = Vector4(std::min(bx1, bx2), std::min(by1, by2), std::max(bx1, bx2), std::max(by1, by2));
}

bool Hitbox::IsPointInside(Vector2& p, bool inclusive = true)
{
	if (inclusive)
		return (p.x <= box.x2()) && (p.x >= box.x1()) && (p.y <= box.y2()) && (p.y >= box.y1());
	return (p.x < box.x2()) && (p.x > box.x1()) && (p.y < box.y2()) && (p.y > box.y1());
}

bool Hitbox::DoesBoxOverlap(Vector4& _box, bool inclusive = true)
{
	if (inclusive)
		return (box.x1() <= _box.x2()) && (_box.x1() <= box.x2()) && (box.y1() <= _box.y2()) && (_box.y1() <= box.y2());
	return (box.x1() < _box.x2()) && (_box.x1() < box.x2()) && (box.y1() < _box.y2()) && (_box.y1() < box.y2());
}

void Hitbox::SetHitbox(Vector4& _box)
{
	box.SetTo(_box);
}

void Hitbox::SetCenter(Vector2& _center)
{
	center.SetTo(_center);
}

void Hitbox::AddToCenter(Vector2& delta)
{
	center += delta;
}

Vector2 Hitbox::GetCenter()
{
	return center;
}

Vector4 Hitbox::GetBox()
{
	return box;
}

void Hitbox::Render()
{

}