#ifndef ENGINE_MOUSE
#define ENGINE_MOUSE

#include "GLFW/glfw3.h"
#include "Engine/Math/Vector.h"

class Mouse {
// can keep this class static because there should only ever be one of them
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);  // glfw enums destinguish button and action

	static float GetMouseX();
	static float GetMouseY();
	static Vector GetMousePos();
	static float GetScaledMouseX();
	static float GetScaledMouseY();
	static Vector GetScaledMousePos();

	static bool IsButtonPressed(int button);
	static bool IsButtonJustPressed(int button);
	static bool IsButtonJustReleased(int button);

	static void ResetJustChanged();

	static const enum mouseButtons { LEFT, RIGHT, MIDDLE };

private:
	static Vector pos;
		
	static bool buttons[];
	static bool justChanged[];
};

#endif