#ifndef ENGINE_VECTOR4
#define ENGINE_VECTOR4

#include <string>
#include "Vector2.h"

/// <summary>
/// Holds four floats in the form of a four dimensional vector, equipped with functions for vector arithmetic and linear algebra.
/// </summary>
class Vector4
{
public:
	static const Vector4 ZERO;
	static const Vector4 ONE;

	Vector4();
	Vector4(std::nullptr_t);
	Vector4(const float& f);
	Vector4(const Vector2& v1, const Vector2& v2);
	Vector4(const float& _x, const float& _y, const float& _z, const float& _w);

	Vector4& operator=(const Vector4& v);
	Vector4& operator+=(const Vector4& v);
	Vector4& operator-=(const Vector4& v);
	Vector4& operator*=(const Vector4& v);
	Vector4& operator*=(const float f);
	Vector4& operator/=(const Vector4& v);
	Vector4 operator+(const Vector4& v) const;
	Vector4 operator-(const Vector4& v) const;
	Vector4 operator*(const Vector4& v) const;
	Vector4 operator*(const float f) const;
	Vector4 operator/(const Vector4& v) const;
	Vector4 operator/(const float f) const;
	bool operator==(const Vector4& v) const;
	bool operator!=(const Vector4& v) const;

	/// <summary>
	/// Returns the dot product of the two vectors
	/// </summary>
	/// <returns>a float</returns>
	static float Dot(const Vector4& a, const Vector4& b);

	/// <summary>
	/// Returns the length of the vector
	/// </summary>
	/// <returns>a float</returns>
	static float Len(const Vector4& v);

	/// <summary>
	/// Return the square of the length of the vector
	/// </summary>
	/// <returns>a float</returns>
	static float Len2(const Vector4& v);

	/// <summary>
	/// Returns the sum of the two vectors
	/// </summary>
	/// <returns>a Vector4</returns>
	static Vector4 Add(const Vector4& a, const Vector4& b);

	/// <summary>
	/// Returns a vector scaled by (scale)
	/// </summary>
	/// <returns>a Vector4</returns>
	static Vector4 Scale(const Vector4& v, float scale);

	/// <summary>
	/// Finds the distance between the two points represented as Vector4s
	/// </summary>
	/// <returns>a float</returns>
	static float DistBetween(const Vector4& v1, const Vector4& v2);

	/// <summary>
	/// Finds the square of the distance between the two points represent as Vector4s
	/// </summary>
	/// <returns>a float</returns>
	static float Dist2Between(const Vector4& v1, const Vector4& v2);

	/// <summary>
	/// Returns the point of intersection of the two lines (x1, y1)->(x2, y2) and (x3, y3)->(x4, y4), if it exists, or null otherwise
	/// </summary>
	/// <param name="status">1 -> parallel, 0 -> found intersection, -1 -> no intersection</param>
	/// <returns>a Vector2 containing the point of intersection</returns>
	static Vector2 DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);

	/// <summary>
	/// Returns the point of intersection of the two lines, if it exists, or null otherwise
	/// </summary>
	/// <param name="status">1 -> parallel, 0 -> found intersection, -1 -> no intersection</param>
	/// <returns>a Vector2 containing the point of intersection</returns>
	static Vector2 DoLinesIntersect(const Vector4& v1, const Vector4& v2, int* status);

	/// <summary>
	/// Constrains the vector to the hypercube bounded by (xMin, yMin, zMin, wMin) and (xMax, yMax, zMax, wMax)
	/// </summary>
	static void Constrain(Vector4* v, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float wMin, float wMax);

	/// <summary>
	/// Returns the result of adding (x, y, z, w) to this vector
	/// </summary>
	/// <returns>a Vector4</returns>
	Vector4 Add(float _x, float _y, float _z, float _w);

	/// <summary>
	/// Returns the result of subtracting (x, y, z, w) from this vector
	/// </summary>
	/// <returns>a Vector4</returns>
	Vector4 Sub(float _x, float _y, float _z, float _w);

	/// <summary>
	/// Returns the result of multiplying (x, y, z, w) with this vector
	/// </summary>
	/// <returns>a Vector4</returns>
	Vector4 Mult(float _x, float _y, float _z, float _w);

	/// <summary>
	/// Returns the result of dividing (x, y, z, w) into this vector
	/// </summary>
	/// <returns>a Vector4</returns>
	Vector4 Div(float _x, float _y, float _z, float _w);

	/// <summary>
	/// Returns the dot product of this vector with <x, y, z, w>
	/// </summary>
	/// <returns>a float</returns>
	float Dot(float _x, float _y, float _z, float _w) const;

	/// <summary>
	/// Returns the dot product with this vector
	/// </summary>
	/// <returns>a float</returns>
	float Dot(const Vector4& v) const;

	/// <summary>
	/// Returns the length of this vector
	/// </summary>
	/// <returns>a float</returns>
	float Len() const;

	/// <summary>
	/// Returns the square of the length of this vector. Use this instead of Len() where possible to avoid computation of sqrt().
	/// </summary>
	/// <returns></returns>
	float Len2() const;

	/// <summary>
	/// Returns the vector resized to the given length, by default modifying this vector in the process.
	/// If this vector is Vector4::ZERO, returns Vector4::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector4</returns>
	Vector4 Resize(float len, bool inplace = true);

	/// <summary>
	/// Returns the unit vector pointing in the same direction as this one, by default modifying this vector in the process.
	/// If this vector is Vector4::ZERO, returns Vector4::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector4</returns>
	Vector4 Unitize(bool inplace = true);

	/// <summary>
	/// Returns this vector with length constrained between to range [minLen, maxLen], by default modifying this vector in the process.
	/// If this vector is Vector4::ZERO, returns Vector4::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector4</returns>
	Vector4 Limit(float minLen, float maxLen, bool inplace = true);

	/// <summary>
	/// Returns this vector shortened to maxLen if longer than maxLen, by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector4</returns>
	Vector4 LimitMax(float maxLen, bool inplace = true);

	/// <summary>
	/// Returns this vector lengthened to minLen if shorter than minLen, by default modifying this vector in the process.
	/// If this vector is Vector2::ZERO, returns Vector2::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector4 LimitMin(float minLen, bool inplace = true);

	/// <summary>
	/// Returns this vector projected onto 'v', by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector4 ProjOnto(const Vector4& v, bool inplace = true);

	/// <summary>
	/// Generates a spring representation of the vector
	/// </summary>
	/// <returns>a std::string</returns>
	std::string ToString() const;

	/// <summary>
	/// Sets to be equal to 'v'
	/// </summary>
	void SetTo(const Vector4& v);

	/// <summary>
	/// Sets to be equal to <x, y, z, w>
	/// </summary>
	void SetTo(const float& _x, const float& _y, const float& _z, const float& _w);

	/// <summary>
	/// Returns the first two elements of this vector as the point <x, y>
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 p1() const;

	/// <summary>
	/// Returns the last two elements of this vector as the point <z, w>
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 p2() const;
	
	float x;
	float y;
	float z;
	float w;

private:
	void Initialize(const float& _x, const float& _y, const float& _z, const float& _w);
};


#endif