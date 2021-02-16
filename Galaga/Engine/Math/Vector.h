#ifndef ENGINE_VECTOR
#define ENGINE_VECTOR

#include <string>

class Vector {

public:
	static const Vector IHAT;
	static const Vector JHAT;
	static const Vector ZERO;

	static float Cross(Vector a, Vector b);
	static float Dot(Vector a, Vector b);
	static float Len(Vector v);
	static float Len2(Vector v);
	static Vector Add(Vector a, Vector b);
	static Vector Scale(Vector v, float scale);

	static float DistBetween(float x1, float y1, float x2, float y2);
	static float DistBetween(Vector v1, Vector v2);
	static float Dist2Between(float x1, float y1, float x2, float y2);
	static float Dist2Between(Vector v1, Vector v2);

	static Vector DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	static Vector DoLinesIntersect(Vector v1, Vector v2, Vector v3, Vector v4);

	//static float AngleBetween(Vector v1, Vector v2);
	//static float AngleBetweenRad(Vector v1, Vector v2);

	Vector();
	Vector(std::nullptr_t);
	Vector(float _x, float _y);

	// arithmetic
	Vector Add(float _x, float _y);
	Vector Sub(float _x, float _y);
	Vector Mult(float _x, float _y);
	Vector Div(float _x, float _y);

	Vector operator+(Vector v);
	Vector operator-(Vector v);
	Vector operator*(Vector v);
	Vector operator/(Vector v);
	bool operator==(Vector v);

	// vector algrebra
	float Cross(float _x, float _y);
	float Cross(Vector v);
	float Dot(float _x, float _y);
	float Dot(Vector v);
	float Len();
	float Len2();

	Vector Resize(float len);
	Vector Unitize();
	Vector Limit(float minLen, float maxLen);
	Vector LimitMax(float maxLen);
	Vector LimitMin(float minLen);
	Vector Rotate(float degrees);
	Vector RotateRad(float radians);
	Vector Rotate90(bool clockwise);
	Vector ProjOnto(Vector v);

	// object stuff
	Vector GetCopy();
	std::string ToString();

	float x;
	float y;
};

#endif