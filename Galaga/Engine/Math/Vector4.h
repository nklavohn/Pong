#ifndef ENGINE_VECTOR4
#define ENGINE_VECTOR4

#include <string>

class Vector4
{
public:
	// static constants
	static const Vector4 ZERO;
	static const Vector4 ONE;

	// static methods
	static float Dot(Vector4* a, Vector4* b);
	static float Len(Vector4* v);
	static float Len2(Vector4* v);
	static Vector4 Add(Vector4* a, Vector4* b);
	static Vector4 Scale(Vector4* v, float scale);
	static float DistBetween(Vector4* v1, Vector4* v2);
	static float Dist2Between(Vector4* v1, Vector4* v2);
	static Vector DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);
	static Vector DoLinesIntersect(Vector4* v1, Vector4* v2, int* status);
	static void Constrain(Vector4* v, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float wMin, float wMax);

	// constructors
	Vector4();
	Vector4(std::nullptr_t);
	Vector4(float f);
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
	bool operator==(const Vector4& v);
	bool operator!=(const Vector4& v);

	// vector algrebra
	float Dot(float _x, float _y, float _z, float _w);
	float Dot(Vector4* v);
	float Len();
	float Len2();

	Vector4 Resize(float len);
	Vector4 Unitize();
	Vector4 Limit(float minLen, float maxLen);
	Vector4 LimitMax(float maxLen);
	Vector4 LimitMin(float minLen);
	Vector4 ProjOnto(Vector4* v);

	// object stuff
	Vector4 GetCopy();
	std::string ToString();
	
	float x;
	float y;
	float z;
	float w;
};


#endif