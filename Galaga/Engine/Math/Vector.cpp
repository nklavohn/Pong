#include "Vector.h"

// ------- CONSTRUCTORS ------------
Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(std::nullptr_t) {
	x = 0;
	y = 0;
}

Vector::Vector(float _f) {
	x = _f;
	y = _f;
}

Vector::Vector(float _x, float _y) {
	x = _x;
	y = _y;
}

// ------ STATICS -------------
const Vector Vector::IHAT = Vector(1, 0);
const Vector Vector::JHAT = Vector(0, 1);
const Vector Vector::ZERO = Vector(0, 0);
const Vector Vector::ONE = Vector(1, 1);

float Vector::Cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

float Vector::Dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

float Vector::Len(Vector v) {
	return (float)sqrt((double)Vector::Len2(v));
}

float Vector::Len2(Vector v) {
	return v.x * v.x + v.y * v.y;
}

Vector Vector::Add(Vector a, Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}

Vector Vector::Scale(Vector v, float scale) {
	return Vector(v.x * scale, v.y * scale);
}

float Vector::DistBetween(float x1, float y1, float x2, float y2) {
	return (float)sqrt(Dist2Between(x1, y1, x2, y2));
}

float Vector::DistBetween(Vector v1, Vector v2) {
	return DistBetween(v1.x, v1.y, v2.x, v2.y);
}

float Vector::Dist2Between(float x1, float y1, float x2, float y2) {
	const float xDiff = x1 - x2;
	const float yDiff = y1 - y2;
	return xDiff * xDiff + yDiff * yDiff;
}

float Vector::Dist2Between(Vector v1, Vector v2) {
	return Dist2Between(v1.x, v1.y, v2.x, v2.y);
}

/**
 * finds the intersection of the two line segments, if there is one
 * 
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param x3
 * @param y3
 * @param x4
 * @param y4
 * @param status 1 -> parallel, 0 -> found intersection, -1 -> no intersection
 * @return Vector, represent the point of intersection, or null if there is no intersection
 */
Vector Vector::DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int& status) {
	const float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
	if (denom == 0.0f)  // Lines are parallel.
		return nullptr;
	
	const float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
	const float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
	if (ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f) {
		// Get the intersection point.
		return Vector((x1 + ua * (x2 - x1)), (y1 + ua * (y2 - y1)));
	}
	return nullptr;
}

/**
 * finds the intersection of the two line segments, if there is one
 *
 * @param v1
 * @param v2
 * @param v3
 * @param v4
 * @param status 1 -> parallel, 0 -> found intersection, -1 -> no intersection
 * @return Vector, represent the point of intersection, or null if there is no intersection
 */
Vector Vector::DoLinesIntersect(Vector v1, Vector v2, Vector v3, Vector v4, int& status) {
	return DoLinesIntersect(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y, status);
}

// -------- INSTANCE METHODS -------------
Vector Vector::Add(float _x, float _y) {
	return Vector(x + _x, y + _y);
}

Vector Vector::Sub(float _x, float _y) {
	return Vector(x - _x, y - _y);
}

Vector Vector::Mult(float _x, float _y) {
	return Vector(x * _x, y * _y);
}

Vector Vector::Div(float _x, float _y) {
	if (_x == 0 || _y == 0) return nullptr;

	return Vector(x / _x, y / _y);
}

Vector& Vector::operator=(const Vector& v) {
	x = v.x;
	y = v.y;
	
	return *this;
}

Vector Vector::operator+(const Vector& v) {
	return Add(v.x, v.y);
}

Vector Vector::operator-(const Vector& v) {
	return Sub(v.x, v.y);
}

Vector Vector::operator*(const Vector& v) {
	return Mult(v.x, v.y);
}

Vector Vector::operator*(const float f) {
	return Vector(x * f, y * f);
}

Vector Vector::operator/(const Vector& v) {
	return Div(v.x, v.y);
}

bool Vector::operator==(const Vector& v) {
	return (x == v.x) && (y == v.y);
}

bool Vector::operator!=(const Vector& v) {
	return !operator==(v);
}

Vector& Vector::operator-=(const Vector& v) {
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector& Vector::operator+=(const Vector& v) {
	x += v.x;
	y += v.y;

	return *this;
}

Vector& Vector::operator*=(const Vector& v) {
	x *= v.x;
	y *= v.y;

	return *this;
}

Vector& Vector::operator*=(const float f) {
	x *= f;
	y *= f;

	return *this;
}

Vector& Vector::operator/=(const Vector& v) {
	x /= v.x;
	y /= v.y;

	return *this;
}

float Vector::Cross(float _x, float _y) {
	return x * _y - y * _x;
}

float Vector::Cross(const Vector v) {
	return x * v.y - y * v.x;
}

float Vector::Dot(float _x, float _y) {
	return x * _x + y * _y;
}

float Vector::Dot(const Vector v) {
	return x * v.x + y * v.y;
}
float Vector::Len() {
	return (float)sqrt(Len2());
}

float Vector::Len2() {
	return x * x + y * y;
}

Vector Vector::Resize(float len) {
	const float curLen = Len();
	if (curLen == 0) return nullptr;

	const float sclFctr = len / curLen;
	return Vector(x * sclFctr,  y * sclFctr);
}

Vector Vector::Unitize() {
	return Resize(1);
}

Vector Vector::Limit(float minLen, float maxLen) {
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector Vector::LimitMax(float maxLen) {
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);

	return GetCopy();
}

Vector Vector::LimitMin(float minLen) {
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector Vector::Rotate(float degrees) {
	return RotateRad(degrees * 3.14159 / 180);
}

Vector Vector::RotateRad(float radians) {
	const float _cos = (float)cos(radians);
	const float _sin = (float)sin(radians);
	return Vector(x * _cos - y * _sin, x * _sin + y * _cos);
}

Vector Vector::Rotate90(bool clockwise) {
	if (clockwise) return Vector(y, -x);
	return Vector(-y, x);
}

Vector Vector::ProjOnto(Vector v) {
	return Scale(v, Dot(v) / v.Dot(v));
}

// object stuff
Vector Vector::GetCopy() {
	return Vector(x, y);
}

std::string Vector::ToString() {
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

