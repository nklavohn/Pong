#include "Mouse.h"
#include "Engine/Engine.h"
#include "Engine/Math/Camera.h"

Vector2 Mouse::pos = Vector2::ZERO;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 }; // set to the total number of buttons glfw can handle
bool Mouse::justChanged[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y)
{
	// get screen width and height
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	// glfw calculates mouse position from top left, we want to change to bottom left
	pos.x = _x;
	pos.y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	// this method is called when there is an event (that event is either getting pressed or getting released)
	if (button < 0)
		return;

	buttons[button] = action != GLFW_RELEASE;
	justChanged[button] = true;
}

float Mouse::GetX() 
{
	return pos.x;
}

float Mouse::GetY() 
{
	return pos.y;
}

Vector2 Mouse::GetDisplayPos() 
{
	return pos;
}

float Mouse::GetScaledX() 
{
	return pos.x / Engine::GetScale();
}

float Mouse::GetScaledY() 
{
	return pos.y / Engine::GetScale();
}

Vector2 Mouse::GetScaledDisplayPos() 
{
	return pos / Engine::GetScale();
}

Vector2 Mouse::GetWorldPos()
{
	return Camera::ToWorldCoords(pos / Engine::GetScale(), Camera::F_PIXEL_TO_METERS);
}

bool Mouse::IsButtonJustPressed(const int& button)
{
	return buttons[button] && justChanged[button];
}

bool Mouse::IsButtonJustReleased(const int& button)
{
	return !buttons[button] && justChanged[button];
}

bool Mouse::IsButtonPressed(const int& button)
{
	return buttons[button];
}

void Mouse::ResetJustChanged() {
	for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) justChanged[i] = false;
}