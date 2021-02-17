#include "Screen.h"
#include "Engine/Engine.h"

Screen::Screen() {
	width = 0;
	height = 0;
	color = Color::BLACK;
}

Screen::Screen(int w, int h) {
	width = w;
	height = h;
	color = Color(0.8, 0.8, 1, 1);
}

Screen::~Screen() {

}

void Screen::SetWidth(int w) {
	width = w;
}

void Screen::SetHeight(int h) {
	height = h;
}

int Screen::GetWidth() {
	return width;
}

int Screen::GetHeight() {
	return height;
}

void Screen::BeginRender() {
	// clear background with a color
	glClearColor(color.r, color.g, color.b, color.a);

	// clear the color and the buffer by bit-wise ORing the two integers together to make a sort of mask of which things to clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::EndRender() {
	glfwSwapBuffers(Engine::window);
}