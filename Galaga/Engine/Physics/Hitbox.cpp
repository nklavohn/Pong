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
	center = center = Vector2((_box.x1() + _box.x2()) / 2, (_box.y1() + _box.y2()) / 2);
	dim = Vector2(std::abs(_box.x1() - _box.x2()), std::abs(_box.y1() - _box.y2()));
	box = Vector4(center - dim / 2, center + dim / 2);
}

Hitbox::~Hitbox()
{

}

bool Hitbox::IsPointInside(Vector2& p, bool inclusive)
{
	if (inclusive)
		return (p.x <= box.x2()) && (p.x >= box.x1()) && (p.y <= box.y2()) && (p.y >= box.y1());
	return (p.x < box.x2()) && (p.x > box.x1()) && (p.y < box.y2()) && (p.y > box.y1());
}

bool Hitbox::DoesBoxOverlap(Vector4& _box, bool inclusive)
{
	if (inclusive)
		return (box.x1() <= _box.x2()) && (_box.x1() <= box.x2()) && (box.y1() <= _box.y2()) && (_box.y1() <= box.y2());
	return (box.x1() < _box.x2()) && (_box.x1() < box.x2()) && (box.y1() < _box.y2()) && (_box.y1() < box.y2());
}

void Hitbox::SetHitbox(Vector4& _box)
{
	center = center = Vector2((_box.x1() + _box.x2()) / 2, (_box.y1() + _box.y2()) / 2);
	dim = Vector2(std::abs(_box.x1() - _box.x2()), std::abs(_box.y1() - _box.y2()));
	box = Vector4(center - dim/2, center - dim/2);
}

void Hitbox::SetCenter(Vector2& _center)
{
	center.SetTo(_center);
	box = Vector4(center - dim / 2, center + dim / 2);
}

void Hitbox::AddToCenter(Vector2& delta)
{
	center += delta;
	box = box.Add(delta.x, delta.y, delta.x, delta.y);
}

Vector2 Hitbox::GetCenter()
{
	return center;
}

Vector4 Hitbox::GetBox()
{
	return box;
}

void Hitbox::Render(Color c)
{
	Vector4 displayPos = Camera::ToDisplayCoords(box, Camera::F_METER_TO_PIXELS);
	ShapeRenderer::StrokeBox(c, displayPos);
}