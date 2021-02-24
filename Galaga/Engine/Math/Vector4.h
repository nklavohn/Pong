#ifndef ENGINE_VECTOR4
#define ENGINE_VECTOR4

#include <string>
#include "Vector2.h"

class Vector4
{
public:
	// static constants
	static const Vector4 ZERO;
	static const Vector4 ONE;

	// static methods
	static float Dot(const Vector4& a, const Vector4& b);
	static float Len(const Vector4& v);
	static float Len2(const Vector4& v);
	static Vector4 Add(const Vector4& a, const Vector4& b);
	static Vector4 Scale(const Vector4& v, float scale);
	static float DistBetween(const Vector4& v1, const Vector4& v2);
	static float Dist2Between(const Vector4& v1, const Vector4& v2);
	static Vector2 DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);
	static Vector2 DoLinesIntersect(const Vector4& v1, const Vector4& v2, int* status);
	static void Constrain(Vector4* v, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float wMin, float wMax);

	// constructors
	Vector4();
	Vector4(std::nullptr_t);
	Vector4(float f);
	Vector4(Vector2 v1, Vector2 v2);
	Vector4(float _x, float _y, float _z, float _w);

	// arithmetic
	Vector4 Add(float _x, float _y, float _z, float _w);
	Vector4 Sub(float _x, float _y, float _z, float _w);
	Vector4 Mult(float _x, float _y, float _z, float _w);
	Vector4 Div(float _x, float _y, float _z, float _w);

	Vector4& operator=(const Vector4& v);
	Vector4& operator+=(const Vector4& v);
	Vector4& operator-=(const Vector4& v);
	Vector4& operator*=(const Vector4& v);
	Vector4& operator*=(const float f);
	Vector4& operator/=(const Vector4& v);
	Vector4 operator+(const Vector4& v);
	Vector4 operator-(const Vector4& v);
	Vector4 operator*(const Vector4& v);
	Vector4 operator*(const float f);
	Vector4 operator/(const Vector4& v);
	Vector4 operator/(const float f);
	bool operator==(const Vector4& v);
	bool operator!=(const Vector4& v);

	// vector algrebra
	float Dot(float _x, float _y, float _z, float _w) const;
	float Dot(const Vector4& v) const;
	float Len() const;
	float Len2() const;

	Vector4 Resize(float len, bool inplace = true);
	Vector4 Unitize(bool inplace = true);
	Vector4 Limit(float minLen, float maxLen, bool inplace = true);
	Vector4 LimitMax(float maxLen, bool inplace = true);
	Vector4 LimitMin(float minLen, bool inplace = true);
	Vector4 ProjOnto(const Vector4& v, bool inplace = true);

	// object stuff
	Vector4 GetCopy() const;
	std::string ToString() const;
	void SetTo(const Vector4& v);
	void SetTo(float _x, float _y, float _z, float _w);

	Vector2 p1() const;
	Vector2 p2() const;
	
	float x;
	float y;
	float z;
	float w;

private:
	void Initialize(float _x, float _y, float _z, float _w);
};


#endif