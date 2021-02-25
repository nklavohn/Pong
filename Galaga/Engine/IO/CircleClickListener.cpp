#include "CircleClickListener.h"
#include "Engine/IO/Mouse.h"

CircleClickListener::CircleClickListener()
{
	button = -1;
	hitcircle = Hitcircle();
}

CircleClickListener::CircleClickListener(int _button, Hitcircle _hitcircle)
{
	button = _button;
	hitcircle = _hitcircle;
}

CircleClickListener::~CircleClickListener()
{

}

bool CircleClickListener::Listen() const
{
	return Mouse::IsButtonJustPressed(button) && hitcircle.IsPointInside(Mouse::GetWorldPos());
}

void CircleClickListener::Act()
{

}

void CircleClickListener::SetPos(const Vector2& pos)
{
	hitcircle.SetCenter(pos);
}

void CircleClickListener::AddToPos(const Vector2& delta)
{
	hitcircle.AddToCenter(delta);
}

void CircleClickListener::Render() const
{
	hitcircle.Render(Color::BLUE);
}