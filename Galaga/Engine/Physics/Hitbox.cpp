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

bool Hitbox::IsPointInside(const Vector2& p, bool inclusive)
{
	if (inclusive)
		return (p.x <= box.z) && (p.x >= box.x) && (p.y <= box.w) && (p.y >= box.y);
	return (p.x < box.z) && (p.x > box.x) && (p.y < box.w) && (p.y > box.y);
}

bool Hitbox::DoesBoxOverlap(const Vector4& _box, bool inclusive)
{
	if (inclusive)
		return (box.x <= _box.z) && (_box.x <= box.z) && (box.y <= _box.w) && (_box.y <= box.w);
	return (box.x < _box.z) && (_box.x < box.z) && (box.y < _box.w) && (_box.y < box.w);
}

void Hitbox::SetHitbox(const Vector4& _box)
{
	center = center = Vector2((_box.x + _box.z) / 2, (_box.y + _box.w) / 2);
	dim = Vector2(std::abs(_box.x - _box.z), std::abs(_box.y - _box.w));
	box = Vector4(center - dim/2, center - dim/2);
}

void Hitbox::SetCenter(const Vector2& _center)
{
	center.SetTo(_center);
	box = Vector4(center - dim / 2, center + dim / 2);
}

void Hitbox::AddToCenter(const Vector2& delta)
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

void Hitbox::Render(const Color& c)
{
	Vector4 displayPos = Camera::ToDisplayCoords(box, Camera::F_METER_TO_PIXELS);
	ShapeRenderer::StrokeBox(c, displayPos);
}

Vector2 Hitbox::GetDim()
{
	return Vector2(box.z - box.x, box.w - box.y);
}