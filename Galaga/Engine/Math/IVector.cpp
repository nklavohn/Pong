#include "IVector.h"

IVector::IVector()
{
	x = 0;
	y = 0;
}

IVector::IVector(std::nullptr_t)
{
	x = 0;
	y = 0;
}

IVector::IVector(int i)
{
	x = i;
	y = i;
}

IVector::IVector(int _x, int _y)
{
	x = _x;
	y = _y;
}

const IVector IVector::ZERO = IVector(0, 0);
const IVector IVector::ONE = IVector(1, 1);

IVector IVector::Add(int _x, int _y)
{
	return IVector(x + _x, y + _y);
}

IVector IVector::Sub(int _x, int _y)
{
	return IVector(x - _x, y - _y);
}

IVector IVector::Mult(int _x, int _y)
{
	return IVector(x * _x, y * _y);
}

IVector IVector::Div(int _x, int _y)
{
	return IVector(x / _x, y / _y);
}

IVector& IVector::operator=(const IVector& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

IVector& IVector::operator+=(const IVector& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

IVector& IVector::operator-=(const IVector& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}
IVector& IVector::operator*=(const IVector& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

IVector& IVector::operator*=(const int i)
{
	x *= i;
	y *= i;

	return *this;
}

IVector& IVector::operator/=(const IVector& v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}

IVector IVector::operator+(const IVector& v)
{
	return Add(v.x, v.y);
}

IVector IVector::operator-(const IVector& v)
{
	return Sub(v.x, v.y);
}

IVector IVector::operator*(const IVector& v)
{
	return Mult(v.x, v.y);
}

IVector IVector::operator*(const int i)
{
	return Mult(i, i);
}

IVector IVector::operator/(const IVector& v)
{
	return Div(v.x, v.y);
}

bool IVector::operator==(const IVector& v)
{
	return (x == v.x) && (y == v.y);
}

bool IVector::operator!=(const IVector& v)
{
	return (x != v.x) && (y != v.y);
}

IVector IVector::GetCopy()
{
	return IVector(x, y);
}

std::string IVector::ToString()
{
	return "[" + std::to_string(x) + "," + std::to_string(y) + "]";
}

Vector IVector::ToVector()
{
	return Vector((float)x, (float)y);
}