#include "Keyboard.h"

bool Keyboard::keysPressed[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysJustPressed[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysJustReleased[GLFW_KEY_LAST] = { 0 };

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key < 0)
		return;

	if (action != GLFW_RELEASE && keysPressed[key] == false) {
		keysJustPressed[key] = true;
		keysJustReleased[key] = false;
	}

	if (action == GLFW_RELEASE && keysPressed[key] == true) {
		keysJustPressed[key] = false;
		keysJustReleased[key] = true;
	}
}

bool Keyboard::IsKeyJustPressed(int key) {
	bool x = keysJustPressed[key];
	keysJustPressed[key] = false;
	return x;
}

bool Keyboard::IsKeyJustReleased(int key) {
	bool x = keysJustReleased[key];
	keysJustReleased[key] = false;
	return x;
}

bool Keyboard::IsKeyPressed(int key) {
	return keysPressed[key];
}