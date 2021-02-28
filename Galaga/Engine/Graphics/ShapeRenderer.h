#ifndef ENGINE_SHAPERENDERER
#define ENGINE_SHAPERENDERER

#include "Engine/Graphics/Color.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

class ShapeRenderer
{
public:
	static void DrawLine(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth = -1, bool convertToDisplayPos = true);
	static void DrawLine(const Color& c, const Vector4& line, float lineWidth = -1, bool convertToDisplayPos = true);

	static void DrawVector(const Color& c, const Vector2& head, const Vector2& tail, float lineWidth = -1, bool convertToDisplayPos = true);

	static void StrokeBox(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth = -1, bool convertToDisplayPos = true);
	static void StrokeBox(const Color& c, const Vector4& box, float lineWidth = -1, bool convertToDisplayPos = true);

	static void FillBox(const Color& c, const Vector2& p1, const Vector2& p2, bool convertToDisplayPos = true);
	static void FillBox(const Color& c, const Vector4& box, bool convertToDisplayPos = true);

	static void DrawBox(const Color& fill, const Color& stroke, const Vector2& p1, const Vector2& p2, float lineWidth = -1, bool convertToDisplayPos = true);
	static void DrawBox(const Color& fill, const Color& stroke, const Vector4& box, float lineWidth = -1, bool convertToDisplayPos = true);

	static void StrokeCircle(const Color& c, const Vector2& center, float r, float sides = -1, float linewidth = -1, bool convertToDisplayPos = true);
	static void FillCircle(const Color& c, const Vector2& center, float r, float sides = -1, bool convertToDisplayPos = true);
	static void DrawCircle(const Color& fill, const Color& stroke, const Vector2& center, float r, float sides = -1, float linewidth = -1, bool convertToDisplayPos = true);

private:
	static void Start(const Color& c, float lineWidth);
	static void Start(const Color& c);
	static void End();

	static void VectorHelper(const Vector2& p1, const Vector2& p2);
	static void LineHelper(const Vector2& p1, const Vector2& p2);
	static void BoxHelper(const Vector2& p1, const Vector2& p2);
	static void CircleHelper(const Vector2& center, float r, float sides);

	static Vector2 ConvertCoords(const Vector2& v);
	static Vector4 ConvertCoords(const Vector4& v);
};

#endif