#ifndef ENGINE_SHAPERENDERER
#define ENGINE_SHAPERENDERER

#include "Engine/Graphics/Color.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

class ShapeRenderer
{
public:
	static void DrawLine(Color c, Vector2 p1, Vector2 p2, float lineWidth = 2);
	static void DrawLine(Color c, Vector4 line, float lineWidth = 2);

	static void StrokeBox(Color c, Vector2 p1, Vector2 p2, float lineWidth = 2);
	static void StrokeBox(Color c, Vector4 box, float lineWidth = 2);

	static void FillBox(Color c, Vector2 p1, Vector2 p2);
	static void FillBox(Color c, Vector4 box);

	static void DrawBox(Color fill, Color stroke, Vector2 p1, Vector2 p2, float lineWidth = 2);
	static void DrawBox(Color fill, Color stroke, Vector4 box, float lineWidth = 2);

	static void StrokeCircle(Color c, Vector2 center, float r, float sides = -1, float linewidth = 2);
	static void FillCircle(Color c, Vector2 center, float r, float sides = -1);
	static void DrawCircle(Color fill, Color stroke, Vector2 center, float r, float sides = -1, float linewidth = 2);

private:
	static void Start(Color c, float lineWidth);
	static void Start(Color c);
	static void End();

	static void BoxHelper(Vector2 p1, Vector2 p2);
	static void CircleHelper(Vector2 center, float r, float sides);
};

#endif