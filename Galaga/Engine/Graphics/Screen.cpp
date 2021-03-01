#include "Screen.h"
#include "Engine/Engine.h"

Screen::Screen()
{
	dim = IVector2::ZERO;
	color = Color::BLACK;
}

Screen::Screen(const IVector2& _dim)
{
	dim = _dim;
	color = Color(0.8, 0.8, 1, 1);
}

Screen::~Screen()
{

}

void Screen::SetDim(const IVector2& _dim)
{
	dim = _dim;
}

int Screen::GetWidth() const 
{
	return dim.x;
}

int Screen::GetHeight() const 
{
	return dim.y;
}

IVector2 Screen::GetDim() const
{
	return dim;
}

void Screen::BeginRender() const 
{
	// clear background with a color
	glClearColor(color.r, color.g, color.b, color.a);

	// clear the color and the buffer by bit-wise ORing the two integers together to make a sort of mask of which things to clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::EndRender() const 
{
	glfwSwapBuffers(Engine::window);
}