#include "Keyboard.h"
#include <iostream>
using namespace std;

bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::justChanged[GLFW_KEY_LAST] = { 0 };

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (key < 0)
		return;

	keys[key] = action != GLFW_RELEASE;
	justChanged[key] = true;
}

bool Keyboard::IsKeyJustPressed(int key) 
{
	return keys[key] && justChanged[key];
}

bool Keyboard::IsKeyJustReleased(int key) 
{
	return !keys[key] && justChanged[key];
}

bool Keyboard::IsKeyPressed(int key) 
{
	return keys[key];
}

void Keyboard::ResetJustChanged()
{
	for (int i = 0; i < GLFW_KEY_LAST; i++) justChanged[i] = false;
}