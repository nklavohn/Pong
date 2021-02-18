#ifndef ENGINE_IVECTOR
#define ENGINE_IVECTOR

#include "Vector.h"
#include <string>

class IVector
{
public:
	static const IVector ZERO;
	static const IVector ONE;

	IVector();
	IVector(std::nullptr_t);
	IVector(int i);
	IVector(int _x, int _y);

	IVector Add(int _x, int _y);
	IVector Sub(int _x, int _y);
	IVector Mult(int _x, int _y);
	IVector Div(int _x, int _y);

	IVector& operator=(const IVector& v);
	IVector& operator+=(const IVector& v);
	IVector& operator-=(const IVector& v);
	IVector& operator*=(const IVector& v);
	IVector& operator*=(const int i);
	IVector& operator/=(const IVector& v);
	IVector operator+(const IVector& v);
	IVector operator-(const IVector& v);
	IVector operator*(const IVector& v);
	IVector operator*(const int i);
	IVector operator/(const IVector& v);
	bool operator==(const IVector& v);
	bool operator!=(const IVector& v);

	IVector GetCopy();
	std::string ToString();
	Vector ToVector();

	int x;
	int y;
};

#endif