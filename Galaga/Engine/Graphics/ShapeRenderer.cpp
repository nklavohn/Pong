#include "ShapeRenderer.h"
#include "GLFW/glfw3.h"
#include "Engine/Math/Camera.h"
#include "Engine/Engine.h"

#include <algorithm>
constexpr float CIRCLE_GRANULARITY = 4;
constexpr float CIRCLE_MIN_SIDES = 8;

void ShapeRenderer::Start(const Color& c, float lineWidth)
{
	if (lineWidth < 0)
		lineWidth = 2;

	glLoadIdentity();
	glColor4f(c.r, c.g, c.b, c.a);
	glLineWidth(lineWidth);
}

void ShapeRenderer::Start(const Color& c)
{
	glLoadIdentity();
	glColor4f(c.r, c.g, c.b, c.a);
}

void ShapeRenderer::End()
{
	glEnd();
}

void ShapeRenderer::DrawLine(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth, bool convertToDisplayPos)
{
	Start(c, lineWidth);
	glBegin(GL_LINES);

	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(p1);
		Vector2 p2Display = ConvertCoords(p2);
		LineHelper(p1Display, p2Display);
	}
	else
	{
		LineHelper(p1, p2);
	}

	End();
}

void ShapeRenderer::DrawLine(const Color& c, const Vector4& line, float lineWidth, bool convertToDisplayPos)
{
	Start(c, lineWidth);
	glBegin(GL_LINES);

	if (convertToDisplayPos)
	{
		Vector4 lineDisplay = ConvertCoords(line);
		LineHelper(lineDisplay.p1(), lineDisplay.p2());
	}
	else
	{
		LineHelper(line.p1(), line.p2());
	}
	End();
}

void ShapeRenderer::LineHelper(const Vector2& p1, const Vector2& p2)
{
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
}

void ShapeRenderer::DrawVector(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth, bool convertToDisplayPos)
{
	
	Start(c, lineWidth);
	glBegin(GL_LINES);

	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(p1);
		Vector2 p2Display = ConvertCoords(p2);
		VectorHelper(p1Display, p2Display);
	}
	else 
	{
		VectorHelper(p1, p2);
	}

	End();
}

void ShapeRenderer::VectorHelper(const Vector2& p1, const Vector2& p2)
{
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);

	Vector2 arrowHead = (p2 - p1).Resize(5 / Engine::GetScale()).Rotate(150);

	glVertex2f(p2.x, p2.y);
	glVertex2f(p2.x + arrowHead.x, p2.y + arrowHead.y);

	arrowHead.Rotate(60);

	glVertex2f(p2.x, p2.y);
	glVertex2f(p2.x + arrowHead.x, p2.y + arrowHead.y);
}

void ShapeRenderer::StrokeBox(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth, bool convertToDisplayPos)
{
	Start(c, lineWidth);
	glBegin(GL_LINE_LOOP);
	
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(p1);
		Vector2 p2Display = ConvertCoords(p2);
		BoxHelper(p1Display, p2Display);
	}
	else
	{
		BoxHelper(p1, p2);
	}

	End();
}

void ShapeRenderer::StrokeBox(const Color& c, const Vector4& box, float lineWidth, bool convertToDisplayPos)
{
	Start(c, lineWidth);
	glBegin(GL_LINE_LOOP);
	
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(box.p1());
		Vector2 p2Display = ConvertCoords(box.p2());
		BoxHelper(p1Display, p2Display);
	}
	else
	{
		BoxHelper(box.p1(), box.p2());
	}

	End();
}

void ShapeRenderer::FillBox(const Color& c, const Vector2& p1, const Vector2& p2, bool convertToDisplayPos)
{
	Start(c);
	glBegin(GL_POLYGON);
	
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(p1);
		Vector2 p2Display = ConvertCoords(p2);
		BoxHelper(p1Display, p2Display);
	}
	else
	{
		BoxHelper(p1, p2);
	}

	End();
}

void ShapeRenderer::FillBox(const Color& c, const Vector4& box, bool convertToDisplayPos)
{
	Start(c);
	glBegin(GL_POLYGON);
	
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(box.p1());
		Vector2 p2Display = ConvertCoords(box.p2());
		BoxHelper(p1Display, p2Display);
	}
	else
	{
		BoxHelper(box.p1(), box.p2());
	}

	End();
}

void ShapeRenderer::DrawBox(const Color& fill, const Color& stroke, const Vector2& p1, const Vector2& p2, float lineWidth, bool convertToDisplayPos)
{
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(p1);
		Vector2 p2Display = ConvertCoords(p2);
		FillBox(fill, p1Display, p2Display, false);
		StrokeBox(stroke, p1Display, p2Display, lineWidth, false);
	}
	else
	{
		FillBox(fill, p1, p2, false);
		StrokeBox(stroke, p1, p2, lineWidth, false);
	}
}

void ShapeRenderer::DrawBox(const Color& fill, const Color& stroke, const Vector4& box, float lineWidth, bool convertToDisplayPos)
{
	if (convertToDisplayPos)
	{
		Vector2 p1Display = ConvertCoords(box.p1());
		Vector2 p2Display = ConvertCoords(box.p2());
		FillBox(fill, p1Display, p2Display, false);
		StrokeBox(stroke, p1Display, p2Display, lineWidth, false);
	}
	else
	{
		FillBox(fill, box.p1(), box.p2(), false);
		StrokeBox(stroke, box.p1(), box.p2(), lineWidth, false);
	}
	
}

void ShapeRenderer::BoxHelper(const Vector2& p1, const Vector2& p2)
{
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glVertex2f(p1.x, p2.y);
}

void ShapeRenderer::StrokeCircle(const Color& c, const Vector2& center, float r, float sides, float linewidth, bool convertToDisplayPos)
{
	Start(c, linewidth);
	glBegin(GL_LINE_LOOP);

	if (convertToDisplayPos)
	{
		Vector2 centerDisplay = ConvertCoords(center);
		float rDisplay = Camera::ToPixels(r);
		CircleHelper(centerDisplay, rDisplay, sides);
	}
	else
	{
		CircleHelper(center, r, sides);
	}

	glEnd();
}

void ShapeRenderer::FillCircle(const Color& c, const Vector2& center, float r, float sides, bool convertToDisplayPos)
{
	Start(c);
	glBegin(GL_POLYGON);

	if (convertToDisplayPos)
	{
		Vector2 centerDisplay = ConvertCoords(center);
		float rDisplay = Camera::ToPixels(r);
		CircleHelper(centerDisplay, rDisplay, sides);
	}
	else
	{
		CircleHelper(center, r, sides);
	}

	glEnd();
}

void ShapeRenderer::DrawCircle(const Color& fill, const Color& stroke, const Vector2& center, float r, float sides, float linewidth, bool convertToDisplayPos)
{
	if (convertToDisplayPos)
	{
		Vector2 centerDisplay = ConvertCoords(center);
		float rDisplay = Camera::ToPixels(r);
		FillCircle(fill, centerDisplay, rDisplay, sides, false);
		StrokeCircle(stroke, centerDisplay, rDisplay, sides, linewidth, false);
	}
	else
	{
		FillCircle(fill, center, r, sides, false);
		StrokeCircle(stroke, center, r, sides, linewidth, false);
	}
}

void ShapeRenderer::CircleHelper(const Vector2& center, float r, float sides)
{
	if (sides < 0)
		sides = std::max((3.14159F * 2 * r) / CIRCLE_GRANULARITY, CIRCLE_MIN_SIDES);

	float degs = 360 / sides;

	Vector2 radius = Vector2(r, 0);
	for (int i = 0; i < sides; i++)
	{
		glVertex2f(center.x + radius.x, center.y + radius.y);
		radius = radius.Rotate(degs);
	}
}

Vector2 ShapeRenderer::ConvertCoords(const Vector2& v)
{
	return Camera::ToDisplayCoords(v, Camera::F_METERS_TO_PIXELS);
}

Vector4 ShapeRenderer::ConvertCoords(const Vector4& v)
{
	return Camera::ToDisplayCoords(v, Camera::F_METERS_TO_PIXELS);
}
