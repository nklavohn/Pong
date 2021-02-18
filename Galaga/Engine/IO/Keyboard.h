#ifndef ENGINE_KEYBOARD
#define ENGINE_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard {

public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	static bool IsKeyPressed(int key);
	static bool IsKeyJustPressed(int key);
	static bool IsKeyJustReleased(int key);

	static void ResetJustChanged();

	const enum keyValues
	{
		W = GLFW_KEY_W,
		A = GLFW_KEY_A,
		S = GLFW_KEY_S,
		D = GLFW_KEY_D,
		Q = GLFW_KEY_Q,
		E = GLFW_KEY_E,
		Z = GLFW_KEY_Z,
		X = GLFW_KEY_X,
		C = GLFW_KEY_C,
		P = GLFW_KEY_P,
		ESC = GLFW_KEY_ESCAPE
	};

private:
	static bool keys[];
	static bool justChanged[];
	
};

#endif