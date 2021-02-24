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
	static float Cross(const Vector2& a, const Vector2& b);
	static float Dot(const Vector2& a, const Vector2& b);
	static float Len(const Vector2& v);
	static float Len2(const Vector2& v);
	static Vector2 Add(const Vector2& a, const Vector2& b);
	static Vector2 Scale(const Vector2& v, float scale);
	static float DistBetween(float x1, float y1, float x2, float y2);
	static float DistBetween(const Vector2& v1, const Vector2& v2);
	static float Dist2Between(float x1, float y1, float x2, float y2);
	static float Dist2Between(const Vector2& v1, const Vector2& v2);
	static Vector2 DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);
	static Vector2 DoLinesIntersect(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, int* status);
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
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator*(const Vector2& v) const;
	Vector2 operator*(const float f) const;
	Vector2 operator/(const Vector2& v) const;
	Vector2 operator/(const float f) const;
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	// vector algrebra
	float Cross(float _x, float _y) const;
	float Cross(const Vector2& v) const;
	float Dot(float _x, float _y) const;
	float Dot(const Vector2& v) const;
	float Len() const;
	float Len2() const;

	Vector2 Resize(float len, bool inplace = true);
	Vector2 Unitize(bool inplace = true);
	Vector2 Limit(float minLen, float maxLen, bool inplace = true);
	Vector2 LimitMax(float maxLen, bool inplace = true);
	Vector2 LimitMin(float minLen, bool inplace = true);
	Vector2 Rotate(float degrees, bool inplace = true);
	Vector2 RotateRad(float radians, bool inplace = true);
	Vector2 Rotate90(bool clockwise, bool inplace = true);
	Vector2 ProjOnto(const Vector2& v, bool inplace = true);

	// object stuff
	Vector2 GetCopy() const;
	std::string ToString() const;
	void SetTo(const Vector2& v);
	void SetTo(float _x, float _y);

	float x;
	float y;

private:
	void Initialize(float _x, float _y);
};

#endif