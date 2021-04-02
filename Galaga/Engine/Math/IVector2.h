#ifndef ENGINE_IVECTOR
#define ENGINE_IVECTOR

#include "Vector2.h"
#include <string>

/// <summary>
/// Holds two ints in the form of a two dimensional vector, intended for uses like storing two-dimensional indices
/// </summary>
class IVector2
{
public:
	static const IVector2 ZERO;
	static const IVector2 ONE;

	IVector2();
	IVector2(std::nullptr_t);
	IVector2(const int& i);
	IVector2(const int& _x, const int& _y);

	IVector2& operator=(const IVector2& v);
	IVector2& operator+=(const IVector2& v);
	IVector2& operator-=(const IVector2& v);
	IVector2& operator*=(const IVector2& v);
	IVector2& operator*=(int i);
	IVector2& operator/=(const IVector2& v);
	IVector2 operator+(const IVector2& v) const;
	IVector2 operator-(const IVector2& v) const;
	IVector2 operator*(const IVector2& v) const;
	IVector2 operator*(int i) const;
	IVector2 operator/(const IVector2& v) const;
	bool operator==(const IVector2& v) const;
	bool operator!=(const IVector2& v) const;

	/// <summary>
	/// Returns the result of adding (x, y) to this vector
	/// </summary>
	/// <returns>an IVector2</returns>
	IVector2 Add(int _x, int _y);

	/// <summary>
	/// Returns the result of subtracting (x, y) from this vector
	/// </summary>
	/// <returns>an IVector2</returns>
	IVector2 Sub(int _x, int _y);

	/// <summary>
	/// Returns the result of multiplying (x, y) with this vector
	/// </summary>
	/// <returns>an IVector2</returns>
	IVector2 Mult(int _x, int _y);

	/// <summary>
	/// Returns the result of dividing (x, y) into this vector. Divide by 0 is not checked.
	/// </summary>
	/// <returns>an IVector2</returns>
	IVector2 Div(int _x, int _y);

	/// <summary>
	/// Generates a spring representation of the vector
	/// </summary>
	/// <returns>a std::string</returns>
	std::string ToString() const;

	/// <summary>
	/// Returns this vector converted to a Vector2 (int to float)
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 ToVector() const;

	/// <summary>
	/// Sets to be equal to <x, y>
	/// </summary>
	void SetTo(int _x, int _y);

	/// <summary>
	/// Sets to be equal to 'v'
	/// </summary>
	void SetTo(const IVector2& v);

	int x;
	int y;

private:
	void Initialize(const int& _x, const int& _y);
};

#endif