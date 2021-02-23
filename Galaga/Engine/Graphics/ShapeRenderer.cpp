#include "ShapeRenderer.h"
#include "GLFW/glfw3.h"

void ShapeRenderer::Start(Color c, float lineWidth)
{
	glLoadIdentity();
	glColor4f(c.r, c.g, c.b, c.a);
	glLineWidth(lineWidth);
}

void ShapeRenderer::Start(Color c)
{
	glLoadIdentity();
	glColor4f(c.r, c.g, c.b, c.a);
}

void ShapeRenderer::End()
{
	glEnd();
}

void ShapeRenderer::DrawLine(Color c, Vector2 p1, Vector2 p2, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_LINE);
	{
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
	}
	End();
}

void ShapeRenderer::DrawLine(Color c, Vector4 line, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_LINE);
	{
		glVertex2f(line.x, line.y);
		glVertex2f(line.z, line.w);
	}
	End();
}

void ShapeRenderer::StrokeBox(Color c, Vector2 p1, Vector2 p2, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_LINE_LOOP);
	
	BoxHelper(p1, p2);

	End();
}

void ShapeRenderer::StrokeBox(Color c, Vector4 box, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_LINE_LOOP);
	
	BoxHelper(box.p1(), box.p2());

	End();
}

void ShapeRenderer::FillBox(Color c, Vector2 p1, Vector2 p2)
{
	Start(c);
	glBegin(GL_POLYGON);
	
	BoxHelper(p1, p2);

	End();
}

void ShapeRenderer::FillBox(Color c, Vector4 box)
{
	Start(c);
	glBegin(GL_POLYGON);
	
	BoxHelper(box.p1(), box.p2());

	End();
}

void ShapeRenderer::DrawBox(Color fill, Color stroke, Vector2 p1, Vector2 p2, float lineWidth)
{
	FillBox(fill, p1, p2);
	StrokeBox(stroke, p1, p2, lineWidth);
}

void ShapeRenderer::DrawBox(Color fill, Color stroke, Vector4 box, float lineWidth)
{
	FillBox(fill, box.p1(), box.p2());
	StrokeBox(stroke, box.p1(), box.p2(), lineWidth);
}

void ShapeRenderer::BoxHelper(Vector2 p1, Vector2 p2)
{
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glVertex2f(p1.x, p2.y);
}

void ShapeRenderer::StrokeCircle(Color c, Vector2 center, float r, float sides, float linewidth)
{
	Start(c, linewidth);
	glBegin(GL_LINE_LOOP);

	CircleHelper(center, r, sides);

	glEnd();
}

void ShapeRenderer::FillCircle(Color c, Vector2 center, float r, float sides)
{
	Start(c);
	glBegin(GL_POLYGON);

	CircleHelper(center, r, sides);

	glEnd();
}

void ShapeRenderer::DrawCircle(Color fill, Color stroke, Vector2 center, float r, float sides, float linewidth)
{
	FillCircle(fill, center, r, sides);
	StrokeCircle(stroke, center, r, sides, linewidth);
}

void ShapeRenderer::CircleHelper(Vector2 center, float r, float sides)
{
	Vector2 radius = Vector2(r, 0);
	float degrees = 0;
	for (int i = 0; i < sides; i++)
	{
		glVertex2f(radius.x, radius.y);
		radius = radius.Rotate(360 / sides);
	}
}
