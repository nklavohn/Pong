#include "Mouse.h"
#include "../Engine.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttonsPressed[GLFW_MOUSE_BUTTON_LAST] = { 0 }; // set to the total number of buttons glfw can handle
bool Mouse::buttonsJustPressed[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsJustReleased[GLFW_MOUSE_BUTTON_LAST] = { 0 };

const enum mouseButtons {
	LEFT = GLFW_MOUSE_BUTTON_LEFT,
	RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
	MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE
};

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y) {
	// get screen width and height
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	// glfw calculates mouse position from top left, we want to change to bottom left
	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	// this method is called when there is an event (that event is either getting pressed or getting released)
	if (button < 0)
		return;

	// possible values for action:
	/* GLFW_RELEASE 0 when button was released
	*  GLFW_PRESS 1 when button was pressed
	*  GLFW_REPEAT 2 when button was held down until it repeated
	*/

	// if the button was not just released and it is currently not pressed, then it was just pressed
	if (action != GLFW_RELEASE && buttonsPressed[button] == false) {
		buttonsJustPressed[button] = true;
		buttonsJustReleased[button] = false;
	}

	// if the button was just released and it is currently pressed, then it was just released
	if (action == GLFW_RELEASE && buttonsPressed[button] == true) {
		buttonsJustPressed[button] = false;
		buttonsJustReleased[button] = true;
	}

	// if the button wasn't released, then the button is pressed
	buttonsPressed[button] = action != GLFW_RELEASE;
}

double Mouse::GetMouseX() {
	return x;
}

double Mouse::GetMouseY() {
	return y;
}

double Mouse::GetScaledMouseX() {
	return x / Engine::GetScale();
}

double Mouse::GetScaledMouseY() {
	return y / Engine::GetScale();
}

bool Mouse::IsButtonJustPressed(int button) {
	// maintains the button just pressed until it is handled by this function, and then it turns it off
	// this function can only be called once and still receive the correct result... that means all justpressed events
	// must be handled by a single function call
	bool x = buttonsJustPressed[button];
	buttonsJustPressed[button] = false;
	return x;
}

bool Mouse::IsButtonJustReleased(int button) {
	// same dealio as above but for just released
	bool x = buttonsJustReleased[button];
	buttonsJustReleased[button] = false;
	return x;
}

bool Mouse::IsButtonPressed(int button) {
	// returns the current state of the button
	return buttonsPressed[button];
}