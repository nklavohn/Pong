#ifndef ENGINE_VECTOR
#define ENGINE_VECTOR

#include <string>

class Vector2 {

public:
	// static constants
	static const Vector2 IHAT;
	static const Vector2 JHAT;
	static const Vector2 ZERO;
	static const Vector2 ONE;

	// static methods
	static float Cross(Vector2* a, Vector2* b);
	static float Dot(Vector2* a, Vector2* b);
	static float Len(Vector2* v);
	static float Len2(Vector2* v);
	static Vector2 Add(Vector2* a, Vector2* b);
	static Vector2 Scale(Vector2* v, float scale);
	static float DistBetween(float x1, float y1, float x2, float y2);
	static float DistBetween(Vector2* v1, Vector2* v2);
	static float Dist2Between(float x1, float y1, float x2, float y2);
	static float Dist2Between(Vector2* v1, Vector2* v2);
	static Vector2 DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);
	static Vector2 DoLinesIntersect(Vector2* v1, Vector2* v2, Vector2* v3, Vector2* v4, int* status);
	static void Constrain(Vector2* v, float xMin, float xMax, float yMin, float yMax);

	//static float AngleBetween(Vector v1, Vector v2);
	//static float AngleBetweenRad(Vector v1, Vector v2);

	// constructors
	Vector2();
	Vector2(std::nullptr_t);
	Vector2(float f);
	Vector2(float _x, float _y);

	// arithmetic
	Vector2 Add(float _x, float _y);
	Vector2 Sub(float _x, float _y);
	Vector2 Mult(float _x, float _y);
	Vector2 Div(float _x, float _y);

	Vector2& operator=(const Vector2& v);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(const Vector2& v);
	Vector2& operator*=(const float f);
	Vector2& operator/=(const Vector2& v);
	Vector2 operator+(const Vector2& v);
	Vector2 operator-(const Vector2& v);
	Vector2 operator*(const Vector2& v);
	Vector2 operator*(const float f);
	Vector2 operator/(const Vector2& v);
	bool operator==(const Vector2& v);
	bool operator!=(const Vector2& v);

	// vector algrebra
	float Cross(float _x, float _y);
	float Cross(const Vector2& v);
	float Dot(float _x, float _y);
	float Dot(const Vector2& v);
	float Len();
	float Len2();

	Vector2 Resize(float len);
	Vector2 Unitize();
	Vector2 Limit(float minLen, float maxLen);
	Vector2 LimitMax(float maxLen);
	Vector2 LimitMin(float minLen);
	Vector2 Rotate(float degrees);
	Vector2 RotateRad(float radians);
	Vector2 Rotate90(bool clockwise);
	Vector2 ProjOnto(Vector2& v);

	// object stuff
	Vector2 GetCopy();
	std::string ToString();

	float x;
	float y;
};

#endif