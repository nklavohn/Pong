#include "Vector2.h"

// ------- CONSTRUCTORS ------------
Vector2::Vector2() 
{
	Initialize(0, 0);
}

Vector2::Vector2(std::nullptr_t)
{
	Initialize(0, 0);
}

Vector2::Vector2(float _f)
{
	Initialize(_f, _f);
}

Vector2::Vector2(float _x, float _y)
{
	Initialize(_x, _y);
}

void Vector2::Initialize(float _x, float _y)
{
	x = _x;
	y = _y;
}

// ------ STATICS -------------
const Vector2 Vector2::IHAT = Vector2(1, 0);
const Vector2 Vector2::JHAT = Vector2(0, 1);
const Vector2 Vector2::ZERO = Vector2(0, 0);
const Vector2 Vector2::ONE = Vector2(1, 1);

float Vector2::Cross(const Vector2& a, const Vector2& b)
{
	return a.x * b.y - a.y * b.x;
}

float Vector2::Dot(const Vector2& a, const Vector2& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::Len(const Vector2& v)
{
	return (float)sqrt((double)Vector2::Len2(v));
}

float Vector2::Len2(const Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}

Vector2 Vector2::Add(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 Vector2::Scale(const Vector2& v, float scale)
{
	return Vector2(v.x * scale, v.y * scale);
}

float Vector2::DistBetween(float x1, float y1, float x2, float y2)
{
	return (float)sqrt(Dist2Between(x1, y1, x2, y2));
}

float Vector2::DistBetween(const Vector2& v1, const Vector2& v2)
{
	return DistBetween(v1.x, v1.y, v2.x, v2.y);
}

float Vector2::Dist2Between(float x1, float y1, float x2, float y2)
{
	const float xDiff = x1 - x2;
	const float yDiff = y1 - y2;
	return xDiff * xDiff + yDiff * yDiff;
}

float Vector2::Dist2Between(const Vector2& v1, const Vector2& v2)
{
	return Dist2Between(v1.x, v1.y, v2.x, v2.y);
}

Vector2 Vector2::DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status)
{
	const float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
	if (denom == 0.0f)  // Lines are parallel.
		*status = 1;
		return nullptr;
	
	const float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
	const float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
	if (ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f) {
		// Get the intersection point.
		*status = 0;
		return Vector2((x1 + ua * (x2 - x1)), (y1 + ua * (y2 - y1)));
	}
	*status = -1;
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
Vector2 Vector2::DoLinesIntersect(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, int* status)
{
	return DoLinesIntersect(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y, status);
}

// none:-1, top-0, right-1, bottom-2, left-3
int Vector2::Constrain(Vector2* v, float xMin, float xMax, float yMin, float yMax)
{
	int boundaryCode = -1;
	if (v->x < xMin)
	{
		v->x = xMin;
		boundaryCode = 3;
	}
	else if (v->x > xMax)
	{
		v->x = xMax;
		boundaryCode = 1;
	}
	if (v->y < yMin)
	{
		v->y = yMin;
		boundaryCode = 2;
	}
	else if (v->y > yMax)
	{
		v->y = yMax;
		boundaryCode = 0;
	}

	return boundaryCode;
}

// -------- INSTANCE METHODS -------------
Vector2 Vector2::Add(float _x, float _y)
{
	return Vector2(x + _x, y + _y);
}

Vector2 Vector2::Sub(float _x, float _y)
{
	return Vector2(x - _x, y - _y);
}

Vector2 Vector2::Mult(float _x, float _y)
{
	return Vector2(x * _x, y * _y);
}

Vector2 Vector2::Div(float _x, float _y)
{
	return Vector2(x / _x, y / _y);
}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator+(const float f) const
{
	return Vector2(x + f, y + f);
}	

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator-(const float f) const
{
	return Vector2(x - f, y - f);
}

Vector2 Vector2::operator*(const Vector2& v) const
{
	return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::operator*(const float f) const
{
	return Vector2(x * f, y * f);
}

Vector2 Vector2::operator/(const Vector2& v) const
{
	return Vector2(x / v.x, y / v.y);
}

Vector2 Vector2::operator/(const float f) const
{
	return Vector2(x / f, y / f);
}

bool Vector2::operator==(const Vector2& v) const
{
	return (x == v.x) && (y == v.y);
}

bool Vector2::operator!=(const Vector2& v) const
{
	return !operator==(v);
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

Vector2& Vector2::operator*=(const float f)
{
	x *= f;
	y *= f;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}

float Vector2::Cross(float _x, float _y) const
{
	return x * _y - y * _x;
}

float Vector2::Cross(const Vector2& v) const
{
	return x * v.y - y * v.x;
}

float Vector2::Dot(float _x, float _y) const
{
	return x * _x + y * _y;
}

float Vector2::Dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}
float Vector2::Len() const
{
	return (float)sqrt(Len2());
}

float Vector2::Len2() const
{
	return x * x + y * y;
}

Vector2 Vector2::Resize(float len, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;

	const float sclFctr = len / curLen;
	Vector2 resized = Vector2(x * sclFctr, y * sclFctr);

	if (inplace)
		Initialize(resized.x, resized.y);

	return resized;
	
}

Vector2 Vector2::Unitize(bool inplace)
{
	return Resize(1, inplace);
}

Vector2 Vector2::Limit(float minLen, float maxLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen, inplace);
	if (curLen < minLen) return Resize(minLen, inplace);

	return GetCopy();
}

Vector2 Vector2::LimitMax(float maxLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen, inplace);

	return GetCopy();
}

Vector2 Vector2::LimitMin(float minLen, bool inplace)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen < minLen) return Resize(minLen, inplace);

	return GetCopy();
}

Vector2 Vector2::Rotate(float degrees, bool inplace)
{
	return RotateRad(degrees * 3.14159 / 180, inplace);
}

Vector2 Vector2::RotateRad(float radians, bool inplace)
{
	const float _cos = (float)cos(radians);
	const float _sin = (float)sin(radians);

	Vector2 rotated = Vector2(x * _cos - y * _sin, x * _sin + y * _cos);

	if (inplace)
		Initialize(rotated.x, rotated.y);

	return rotated;
}

Vector2 Vector2::Rotate90(bool clockwise, bool inplace)
{
	if (clockwise)
	{
		if (inplace)
			Initialize(y, -x);
		return Vector2(y, -x);
	}
	else
	{
		if (inplace)
			Initialize(-y, x);
		return Vector2(-y, x);
	}
}

Vector2 Vector2::ProjOnto(const Vector2& v, bool inplace)
{
	Vector2 proj = Scale(v, Dot(v) / v.Dot(v));

	if (inplace)
		Initialize(proj.x, proj.y);

	return proj;
}

Vector2 Vector2::Flip(bool inplace)
{
	Vector2 flip = Vector2(-x, -y);
	
	if (inplace)
		Initialize(flip.x, flip.y);

	return flip;
}

// object stuff
Vector2 Vector2::GetCopy() const
{
	return Vector2(x, y);
}

std::string Vector2::ToString() const
{
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void Vector2::SetTo(const Vector2& v)
{
	Initialize(v.x, v.y);
}

void Vector2::SetTo(float _x, float _y)
{
	Initialize(_x, _y);
}
