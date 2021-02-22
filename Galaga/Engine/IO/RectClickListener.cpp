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

bool RectClickListener::Listen()
{
	return hitbox.IsPointInside(Mouse::GetMousePos()) && Mouse::IsButtonJustPressed(button);
}

void RectClickListener::Act()
{

}

void RectClickListener::SetPos(Vector2 pos)
{
	hitbox.SetCenter(pos);
}

void RectClickListener::AddToPos(Vector2 delta)
{
	hitbox.AddToCenter(delta);
}

