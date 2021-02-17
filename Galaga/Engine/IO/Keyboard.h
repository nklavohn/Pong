#ifndef ENGINE_KEYBOARD
#define ENGINE_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard {

public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	static bool IsKeyPressed(int key);
	static bool IsKeyJustPressed(int key);
	static bool IsKeyJustReleased(int key);

private:
	static bool keysPressed[];
	static bool keysJustPressed[];
	static bool keysJustReleased[];
};

#endif