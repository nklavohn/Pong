#ifndef ENGINE_MOUSE
#define ENGINE_MOUSE

#include "GLFW/glfw3.h"
#include "Engine/Math/Vector2.h"

class Mouse {
// can keep this class static because there should only ever be one of them
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);  // glfw enums destinguish button and action

	static float GetX();
	static float GetY();
	static Vector2 GetDisplayPos();
	static float GetScaledX();
	static float GetScaledY();
	static Vector2 GetScaledDisplayPos();
	static Vector2 GetWorldPos();

	static bool IsButtonPressed(const int& button);
	static bool IsButtonJustPressed(const int& button);
	static bool IsButtonJustReleased(const int& button);

	static void ResetJustChanged();

	const enum mouseButtons
	{
		LEFT = GLFW_MOUSE_BUTTON_LEFT,
		RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
		MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE
	};

private:
	static Vector2 pos;
		
	static bool buttons[];
	static bool justChanged[];
};

#endif