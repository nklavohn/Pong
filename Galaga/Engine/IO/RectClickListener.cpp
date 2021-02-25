#include "RectClickListener.h"

#include "Mouse.h"

RectClickListener::RectClickListener()
{
	button = -1;
	hitbox = Hitbox();
}

RectClickListener::RectClickListener(int _button, Hitbox _hitbox)
{
	button = _button;
	hitbox = _hitbox;
}

RectClickListener::~RectClickListener()
{

}

bool RectClickListener::Listen() const
{
	return Mouse::IsButtonJustPressed(button) && hitbox.IsPointInside(Mouse::GetWorldPos());
}

void RectClickListener::Act()
{

}

void RectClickListener::SetPos(const Vector2& pos)
{
	hitbox.SetCenter(pos);
}

void RectClickListener::AddToPos(const Vector2& delta)
{
	hitbox.AddToCenter(delta);
}

void RectClickListener::Render() const
{
	hitbox.Render(Color::BLUE);
}