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

	static void DrawBox(Color c, Vector2 p1, Vector2 p2, float lineWidth = 2);
	static void DrawBox(Color c, Vector4 box, float lineWidth = 2);

	static void DrawStrokeBox(Color fill, Color stroke, Vector2 p1, Vector2 p2, float lineWidth = 2);
	static void DrawStrokeBox(Color fill, Color stroke, Vector4 box, float lineWidth = 2);

private:
	static void Start(Color c, float lineWidth);
	static void End();
};

#endif