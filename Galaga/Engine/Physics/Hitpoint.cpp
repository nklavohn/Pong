#include "Hitpoint.h"
#include "Engine/Graphics/ShapeRenderer.h"

Hitpoint::Hitpoint()
{
	center = Vector2::ZERO;
}

Hitpoint::Hitpoint(float cx, float cy)
{
	center = Vector2(cx, cy);
}

Hitpoint::Hitpoint(Vector2 _center)
{
	center = _center;
}

Hitpoint::~Hitpoint()
{

}

bool Hitpoint::IsPointInside(const Vector2& p) const
{
	return false;
}

bool Hitpoint::AreAllPointsInside(const vector<Vector2>& ps) const
{
	return false;
}

bool Hitpoint::DoesLineIntersect(const Vector4& line) const
{
	return false;
}

bool Hitpoint::IsCollidingWith(CollisionDetector* cDetector) const
{
	//TODO implement this function
	return false;
}

void Hitpoint::SetCenter(const Vector2& _center)
{
	center = _center;
}

void Hitpoint::AddToCenter(const Vector2& delta)
{
	center += delta;
}

void Hitpoint::Render(const Color& c) const
{
	ShapeRenderer::FillCircle(Color::YELLOW, center, 3, 6);
}

Vector2 Hitpoint::GetCenter() const
{
	return center;
}
