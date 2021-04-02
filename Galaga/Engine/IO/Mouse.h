#ifndef ENGINE_MOUSE
#define ENGINE_MOUSE

#include "GLFW/glfw3.h"
#include "Engine/Math/Vector2.h"

/// <summary>
/// Handles all input through the mouse, keeping track of the cursor position and which mouse buttons are currently pressed, just pressed, or just released.
/// All methods and parameters are static because there is only one keyboard.
/// </summary>
class Mouse {
public:
	/// <summary>
	/// A callback function passed to a GLFWwindow to let glfw handle mouse position calculation.
	/// </summary>
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);

	/// <summary>
	/// A callback function passed to a GLFWwindow to let glfw handle mouse button input.
	/// </summary>
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	/// <summary>
	/// Returns the x position of the mouse in pixels in display coordinates.
	/// </summary>
	/// <returns>a float</returns>
	static float GetX();

	/// <summary>
	/// Returns the y position of the mouse in pixels in display coordinates
	/// </summary>
	/// <returns>a float</returns>
	static float GetY();

	/// <summary>
	/// Returns a vector holding the position of the mouse in pixels in display coordinates
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 GetDisplayPos();

	/// <summary>
	/// Returns the x position of the mouse in pixels in display coordinates, divided by the scaleup
	/// factor of the Engine to find the 'true' display position instead of the 'apparent' position from the scaling.
	/// </summary>
	/// <returns>a float</returns>
	static float GetScaledX();

	/// <summary>
	/// Returns the y position of the mouse in pixels in display coordinates, divided by the scaleup
	/// factor of the Engine to find the 'true' display position instead of the 'apparent' position from the scaling.
	/// </summary>
	/// <returns>a float</returns>
	static float GetScaledY();

	/// <summary>
	/// Returns the vector holding the position of the mouse in pixels in display coordinates, divided by the scaleup
	/// factor of the Engine to find the 'true' display position instead of the 'apparent' position from the scaling.
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 GetScaledDisplayPos();

	/// <summary>
	/// Returns a vector holding the world position of the mouse, in meters.
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 GetWorldPos();

	/// <summary>
	/// Returns true if the specified mouse button is currently pressed
	/// </summary>
	/// <returns>a boolean</returns>
	static bool IsButtonPressed(const int& button);

	/// <summary>
	/// Returns true if the specified mouse button was just pressed during the previous frame.
	/// </summary>
	/// <returns>a boolean</returns>
	static bool IsButtonJustPressed(const int& button);

	/// <summary>
	/// Returns true if the specified mouse button was just released during the previous frame.
	/// </summary>
	/// <returns>a boolean</returns>
	static bool IsButtonJustReleased(const int& button);

	/// <summary>
	/// Do not call this function outside of the Engine.
	/// Intended to be called once at the end of the update and rendering steps of a frame, at the very end of the Engine's loop.
	/// </summary>
	static void ResetJustChanged();

	/// <summary>
	/// Enum shortcuts for different mouse buttons supported by glfw.
	/// </summary>
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