#ifndef ENGINE_VECTOR
#define ENGINE_VECTOR

#include <string>

class Vector2 {

public:
	static const Vector2 IHAT;
	static const Vector2 JHAT;
	static const Vector2 ZERO;
	static const Vector2 ONE;

	Vector2();
	Vector2(std::nullptr_t);
	Vector2(float f);
	Vector2(float _x, float _y);

	Vector2& operator=(const Vector2& v);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(const Vector2& v);
	Vector2& operator*=(const float f);
	Vector2& operator/=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator+(const float f) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-(const float f) const;
	Vector2 operator*(const Vector2& v) const;
	Vector2 operator*(const float f) const;
	Vector2 operator/(const Vector2& v) const;
	Vector2 operator/(const float f) const;
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	/// <summary>
	/// Returns the magnitude of the cross product the two vectors
	/// </summary>
	/// <returns>a float</returns>
	static float Cross(const Vector2& a, const Vector2& b);

	/// <summary>
	/// Returns the dot product of the two vectors
	/// </summary>
	/// <returns>a float</returns>
	static float Dot(const Vector2& a, const Vector2& b);

	/// <summary>
	/// Returns the length of the vector
	/// </summary>
	/// <returns>a float</returns>
	static float Len(const Vector2& v);

	/// <summary>
	/// Return the square of the length of the vector
	/// </summary>
	/// <returns>a float</returns>
	static float Len2(const Vector2& v);

	/// <summary>
	/// Returns the sum of the two vectors
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 Add(const Vector2& a, const Vector2& b);

	/// <summary>
	/// Returns a vector scaled by (scale)
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 Scale(const Vector2& v, float scale);

	/// <summary>
	/// Finds the distance between points (x1, y1) and (x2, y2)
	/// </summary>
	/// <returns>a float</returns>
	static float DistBetween(float x1, float y1, float x2, float y2);

	/// <summary>
	/// Finds the distance between the two points represented as Vector2s
	/// </summary>
	/// <returns>a float</returns>
	static float DistBetween(const Vector2& v1, const Vector2& v2);

	/// <summary>
	/// Finds the square of the distance between the two points (x1, y1) and (x2, y2)
	/// </summary>
	/// <returns>a float</returns>
	static float Dist2Between(float x1, float y1, float x2, float y2);

	/// <summary>
	/// Finds the square of the distance between the two points represent as Vector2s
	/// </summary>
	/// <returns>a float</returns>
	static float Dist2Between(const Vector2& v1, const Vector2& v2);

	/// <summary>
	/// Returns the point of intersection of the two lines (x1, y1)->(x2, y2) and (x3, y3)->(x4, y4), if it exists, or null otherwise
	/// </summary>
	/// <param name="status">1 -> parallel, 0 -> found intersection, -1 -> no intersection</param>
	/// <returns>a Vector2 containing the point of intersection</returns>
	static Vector2 DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status);
	
	/// <summary>
	/// Returns the point of intersection of the two lines v1->v2, v3->v4, if it exists, or null otherwise
	/// </summary>
	/// <param name="status">1 -> parallel, 0 -> found intersection, -1 -> no intersection</param>
	/// <returns>a Vector2 containing the point of intersection</returns>
	static Vector2 DoLinesIntersect(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, int* status);
	
	/// <summary>
	/// Constrains the vector to the rectangle bounded by (xMin, yMin) and (xMax, yMax)
	/// </summary>
	/// <returns>none:-1, top:0, right:1, bottom:2, left:3</returns>
	static int Constrain(Vector2* v, float xMin, float xMax, float yMin, float yMax);

	/// <summary>
	/// Returns the result of adding (x, y) to this vector
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 Add(float _x, float _y);

	/// <summary>
	/// Returns the result of subtracting (x, y) from this vector
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 Sub(float _x, float _y);

	/// <summary>
	/// Returns the result of multiplying (x, y) with this vector
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 Mult(float _x, float _y);

	/// <summary>
	/// Returns the result of dividing (x, y) into this vector. Divide by 0 is not checked.
	/// </summary>
	/// <returns>a Vector2</returns>
	Vector2 Div(float _x, float _y);

	/// <summary>
	/// Returns the magnitude of the cross product of this vector with <x, y>
	/// </summary>
	/// <returns>a float</returns>
	float Cross(float _x, float _y) const;

	/// <summary>
	/// Returns the magnitude of the cross product with this vector
	/// </summary>
	/// <returns>a float</returns>
	float Cross(const Vector2& v) const;

	/// <summary>
	/// Returns the dot product of this vector with <x, y>
	/// </summary>
	/// <returns>a float</returns>
	float Dot(float _x, float _y) const;

	/// <summary>
	/// Returns the dot product with this vector
	/// </summary>
	/// <returns>a float</returns>
	float Dot(const Vector2& v) const;

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
	/// If this vector is Vector2::ZERO, returns Vector2::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Resize(float len, bool inplace = true);

	/// <summary>
	/// Returns the unit vector pointing in the same direction as this one, by default modifying this vector in the process.
	/// If this vector is Vector2::ZERO, returns Vector2::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Unitize(bool inplace = true);

	/// <summary>
	/// Returns this vector with length constrained between to range [minLen, maxLen], by default modifying this vector in the process.
	/// If this vector is Vector2::ZERO, returns Vector2::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Limit(float minLen, float maxLen, bool inplace = true);

	/// <summary>
	/// Returns this vector shortened to maxLen if longer than maxLen, by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 LimitMax(float maxLen, bool inplace = true);

	/// <summary>
	/// Returns this vector lengthened to minLen if shorter than minLen, by default modifying this vector in the process.
	/// If this vector is Vector2::ZERO, returns Vector2::ZERO
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 LimitMin(float minLen, bool inplace = true);

	/// <summary>
	/// Returns the rotated vector, by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Rotate(float degrees, bool inplace = true);

	/// <summary>
	/// Returns the unit vector pointing in the same direction as this one, by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 RotateRad(float radians, bool inplace = true);

	/// <summary>
	/// Returns this vector rotated by 90 degrees in the direction specified, by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Rotate90(bool clockwise, bool inplace = true);

	/// <summary>
	/// Returns this vector projected onto 'v', by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 ProjOnto(const Vector2& v, bool inplace = true);

	/// <summary>
	/// Returns this vector flipped (a.k.a. rotated 180 degrees), by default modifying this vector in the process.
	/// </summary>
	/// <param name="inplace">true by default. if true, modifies this vector</param>
	/// <returns>a Vector2</returns>
	Vector2 Flip(bool inplace = true);

	/// <summary>
	/// Generates a spring representation of the vector
	/// </summary>
	/// <returns>a std::string</returns>
	std::string ToString() const;

	/// <summary>
	/// Sets to be equal to 'v'
	/// </summary>
	void SetTo(const Vector2& v);

	/// <summary>
	/// Sets to be equal to <x, y>
	/// </summary>
	void SetTo(const float& _x, const float& _y);

	float x;
	float y;

private:
	void Initialize(const float& _x, const float& _y);
};

#endif