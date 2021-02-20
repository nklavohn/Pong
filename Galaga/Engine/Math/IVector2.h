#ifndef ENGINE_IVECTOR
#define ENGINE_IVECTOR

#include "Vector2.h"
#include <string>

class IVector2
{
public:
	static const IVector2 ZERO;
	static const IVector2 ONE;

	IVector2();
	IVector2(std::nullptr_t);
	IVector2(int i);
	IVector2(int _x, int _y);

	IVector2 Add(int _x, int _y);
	IVector2 Sub(int _x, int _y);
	IVector2 Mult(int _x, int _y);
	IVector2 Div(int _x, int _y);

	IVector2& operator=(const IVector2& v);
	IVector2& operator+=(const IVector2& v);
	IVector2& operator-=(const IVector2& v);
	IVector2& operator*=(const IVector2& v);
	IVector2& operator*=(const int i);
	IVector2& operator/=(const IVector2& v);
	IVector2 operator+(const IVector2& v);
	IVector2 operator-(const IVector2& v);
	IVector2 operator*(const IVector2& v);
	IVector2 operator*(const int i);
	IVector2 operator/(const IVector2& v);
	bool operator==(const IVector2& v);
	bool operator!=(const IVector2& v);

	IVector2 GetCopy();
	std::string ToString();
	Vector2 ToVector();

	int x;
	int y;
};

#endif