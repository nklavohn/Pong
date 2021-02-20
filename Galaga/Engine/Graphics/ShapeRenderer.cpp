#include "ShapeRenderer.h"
#include "GLFW/glfw3.h"

void ShapeRenderer::Start(Color c, float lineWidth)
{
	glLoadIdentity();
	glColor4f(c.r, c.g, c.b, c.a);
	glLineWidth(lineWidth);
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
	{
		glVertex2f(p1.x, p1.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p2.x, p1.y);
	}
	End();
}

void ShapeRenderer::StrokeBox(Color c, Vector4 box, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2f(box.x1(), box.y1());
		glVertex2f(box.x2(), box.y1());
		glVertex2f(box.x2(), box.y2());
		glVertex2f(box.x1(), box.y2());
	}
	End();
}

void ShapeRenderer::DrawBox(Color c, Vector2 p1, Vector2 p2, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_POLYGON);
	{
		glVertex2f(p1.x, p1.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p2.x, p1.y);
	}
	End();
}

void ShapeRenderer::DrawBox(Color c, Vector4 box, float lineWidth)
{
	Start(c, lineWidth);
	glBegin(GL_POLYGON);
	{
		glVertex2f(box.x1(), box.y1());
		glVertex2f(box.x2(), box.y1());
		glVertex2f(box.x2(), box.y2());
		glVertex2f(box.x1(), box.y2());
	}
	End();
}

void ShapeRenderer::DrawStrokeBox(Color fill, Color stroke, Vector2 p1, Vector2 p2, float lineWidth)
{
	Start(fill, lineWidth);
	glBegin(GL_POLYGON);
	{
		glVertex2f(p1.x, p1.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p2.x, p1.y);
	}
	End();

	Start(stroke, lineWidth);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2f(p1.x, p1.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p2.x, p1.y);
	}
	End();
}

void ShapeRenderer::DrawStrokeBox(Color fill, Color stroke, Vector4 box, float lineWidth)
{
	Start(fill, lineWidth);
	glBegin(GL_POLYGON);
	{
		glVertex2f(box.x1(), box.y1());
		glVertex2f(box.x2(), box.y1());
		glVertex2f(box.x2(), box.y2());
		glVertex2f(box.x1(), box.y2());
	}
	End();

	Start(stroke, lineWidth);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2f(box.x1(), box.y1());
		glVertex2f(box.x2(), box.y1());
		glVertex2f(box.x2(), box.y2());
		glVertex2f(box.x1(), box.y2());
	}
	End();
}