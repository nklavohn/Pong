#ifndef MOUSE
#define MOUSE

#include "GLFW/glfw3.h"

class Mouse {
// can keep this class static because there should only ever be one of them
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);  // glfw enums destinguish button and action

	static double getMouseX();
	static double getMouseY();

	static bool isButtonPressed(int button);
	static bool isButtonJustPressed(int button);
	static bool isButtonJustReleased(int button);

	static const enum mouseButtons {LEFT, RIGHT, MIDDLE};

private:
	static double x;
	static double y;
		
	static bool buttonsPressed[];  // true if currently held down
	static bool buttonsJustPressed[];  // true if just pressed down
	static bool buttonsJustReleased[];  // true if just released

};

#endif