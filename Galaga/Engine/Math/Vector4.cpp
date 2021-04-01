#include "Vector4.h"
#include "Vector2.h"

#include <iostream>

Vector4::Vector4()
{
	Initialize(0, 0, 0, 0);
}

Vector4::Vector4(std::nullptr_t)
{
	Initialize(0, 0, 0, 0);
}

Vector4::Vector4(const float& f)
{
	Initialize(f, f, f, f);
}

Vector4::Vector4(const Vector2& v1, const Vector2& v2)
{
	Initialize(v1.x, v1.y, v2.x, v2.y);
}

Vector4::Vector4(const float& _x, const float& _y, const float& _z, const float& _w)
{
	Initialize(_x, _y, _z, _w);
}

void Vector4::Initialize(const float& _x, const float& _y, const float& _z, const float& _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

// ------ STATICS -------------
const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);
const Vector4 Vector4::ONE = Vector4(1, 1, 1, 1);

float Vector4::Dot(const Vector4& a, const Vector4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float Vector4::Len(const Vector4& v)
{
	return (float)sqrt(Len2(v));
}

float Vector4::Len2(const Vector4& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

Vector4 Vector4::Add(const Vector4& a, const Vector4& b)
{
	return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector4 Vector4::Scale(const Vector4& v, float scale)
{
	return Vector4(v.x * scale, v.y * scale, v.z * scale, v.w * scale);
}

float Vector4::DistBetween(const Vector4& v1, const Vector4& v2)
{
	Vector4 diff = Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	return Len(diff);
}

float Vector4::Dist2Between(const Vector4& v1, const Vector4& v2)
{
	Vector4 diff = Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	return Len2(diff);
}

Vector2 Vector4::DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status) {
	return Vector2::DoLinesIntersect(x1, y1, x2, y2, x3, y3, x4, y4, status);
}

Vector2 Vector4::DoLinesIntersect(const Vector4& l1, const Vector4& l2, int* status) {
	return DoLinesIntersect(l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, status);
}

void Vector4::Constrain(Vector4* v, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float wMin, float wMax)
{
	if (v->x < xMin) v->x = xMin;
	else if (v->x > xMax) v->x = xMax;
	if (v->y < yMin) v->y = yMin;
	else if (v->y > yMax) v->y = yMax;
	if (v->z < zMin) v->z = zMin;
	else if (v->z > zMax) v->z = zMax;
	if (v->w < wMin) v->w = wMin;
	else if (v->w > wMax) v->w = wMax;
}

Vector4 Vector4::Add(float _x, float _y, float _z, float _w)
{
	return Vector4(x + _x, y + _y, z + _z, w + _w);
}

Vector4 Vector4::Sub(float _x, float _y, float _z, float _w)
{
	return Vector4(x - _x, y - _y, z - _z, w - _w);
}

Vector4 Vector4::Mult(float _x, float _y, float _z, float _w)
{
	return Vector4(x * _x, y * _y, z * _z, w * _w);
}

Vector4 Vector4::Div(float _x, float _y, float _z, float _w)
{
	return Vector4(x / _x, y / _y, z / _z, w / _w);
}

Vector4& Vector4::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

Vector4& Vector4::operator+=(const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

Vector4& Vector4::operator*=(const Vector4& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;

	return *this;
}

Vector4& Vector4::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;

	return *this;
}

Vector4& Vector4::operator/=(const Vector4& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& v) const
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator-(const Vector4& v) const
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4 Vector4::operator*(const Vector4& v) const
{
	return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
}

Vector4 Vector4::operator*(const float f) const
{
	return Vector4(x * f, y * f, z * f, w * f);
}

Vector4 Vector4::operator/(const Vector4& v) const
{
	return Vector4(x / v.x, y / v.y, z / v.z, w / v.w);
}

Vector4 Vector4::operator/(const float f) const
{
	return Vector4(x / f, y / f, z / f, w / f);
}

bool Vector4::operator==(const Vector4& v) const
{
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}

bool Vector4::operator!=(const Vector4& v) const
{
	return !operator==(v);
}

// vector algrebra
float Vector4::Dot(float _x, float _y, float _z, float _w) const
{
	return x * _x + y * _y + z * _z + w * _w;
}

float Vector4::Dot(const Vector4& v) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

float Vector4::Len() const
{
	return (float)sqrt(Len2());
}

float Vector4::Len2() const
{
	return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::Resize(float len, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;

	const float sclFctr = len / curLen;

	if (inplace)
	{
		Initialize(x * sclFctr, y * sclFctr, z * sclFctr, w * sclFctr);
		return *this;
	}

	return Vector4(x * sclFctr, y * sclFctr, z * sclFctr, w * sclFctr);
}

Vector4 Vector4::Unitize(bool inplace)
{
	return Resize(1, inplace);
}

Vector4 Vector4::Limit(float minLen, float maxLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen, inplace);
	if (curLen < minLen) return Resize(minLen, inplace);

	return *this;
}

Vector4 Vector4::LimitMax(float maxLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen, inplace);

	return *this;
}

Vector4 Vector4::LimitMin(float minLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen < minLen) return Resize(minLen, inplace);

	return *this;
}

Vector4 Vector4::ProjOnto(const Vector4& v, bool inplace)
{
	Vector4 proj = Scale(v, Dot(v) / v.Dot(v));

	if (inplace)
		Initialize(proj.x, proj.y, proj.z, proj.w);

	return proj;
}

std::string Vector4::ToString() const
{
	return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "," + std::to_string(w) + ")";
}

void Vector4::SetTo(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

void Vector4::SetTo(const float& _x, const float& _y, const float& _z, const float& _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector2 Vector4::p1() const
{
	return Vector2(x, y);
}

Vector2 Vector4::p2() const
{
	return Vector2(z, w);
}
