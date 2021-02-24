#include "IVector2.h"

IVector2::IVector2()
{
	x = 0;
	y = 0;
}

IVector2::IVector2(std::nullptr_t)
{
	x = 0;
	y = 0;
}

IVector2::IVector2(int i)
{
	x = i;
	y = i;
}

IVector2::IVector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

const IVector2 IVector2::ZERO = IVector2(0, 0);
const IVector2 IVector2::ONE = IVector2(1, 1);

IVector2 IVector2::Add(int _x, int _y)
{
	return IVector2(x + _x, y + _y);
}

IVector2 IVector2::Sub(int _x, int _y)
{
	return IVector2(x - _x, y - _y);
}

IVector2 IVector2::Mult(int _x, int _y)
{
	return IVector2(x * _x, y * _y);
}

IVector2 IVector2::Div(int _x, int _y)
{
	return IVector2(x / _x, y / _y);
}

IVector2& IVector2::operator=(const IVector2& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

IVector2& IVector2::operator+=(const IVector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

IVector2& IVector2::operator-=(const IVector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}
IVector2& IVector2::operator*=(const IVector2& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

IVector2& IVector2::operator*=(int i)
{
	x *= i;
	y *= i;

	return *this;
}

IVector2& IVector2::operator/=(const IVector2& v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}

IVector2 IVector2::operator+(const IVector2& v) const
{
	return IVector2(x + v.x, y + v.y);
}

IVector2 IVector2::operator-(const IVector2& v) const
{
	return IVector2(x - v.x, y - v.y);
}

IVector2 IVector2::operator*(const IVector2& v) const
{
	return IVector2(x * v.x, y * v.y);
}

IVector2 IVector2::operator*(int i) const
{
	return IVector2(x * i, y * i);
}

IVector2 IVector2::operator/(const IVector2& v) const
{
	return IVector2(x / v.x, y / v.y);
}

bool IVector2::operator==(const IVector2& v) const
{
	return (x == v.x) && (y == v.y);
}

bool IVector2::operator!=(const IVector2& v) const
{
	return !operator==(v);
}

IVector2 IVector2::GetCopy() const
{
	return IVector2(x, y);
}

std::string IVector2::ToString() const
{
	return "[" + std::to_string(x) + "," + std::to_string(y) + "]";
}

Vector2 IVector2::ToVector() const
{
	return Vector2((float)x, (float)y);
}

void IVector2::SetTo(int _x, int _y)
{
	x = _x;
	y = _y;
}

void IVector2::SetTo(const IVector2& v)
{
	x = v.x;
	y = v.y;
}
