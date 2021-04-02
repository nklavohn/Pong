#ifndef ENGINE_KEYBOARD
#define ENGINE_KEYBOARD

#include "GLFW/glfw3.h"

/// <summary>
/// A class for handling all input through a keyboard, keeping track of which keys are currently pressed, just pressed, or just released.
/// All methods and parameters are static because there is only one keyboard.
/// </summary>
class Keyboard {

public:
	/// <summary>
	/// A callback function passed to the GLFWwindow to let glfw manage keypress events.
	/// </summary>
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	/// <summary>
	/// Returns true if the specified key is currently pressed.
	/// </summary>
	/// <param name="key"></param>
	/// <returns>a boolean</returns>
	static bool IsKeyPressed(int key);

	/// <summary>
	/// Returns true if the specified key was just pressed during the previous frame.
	/// </summary>
	/// <param name="key"></param>
	/// <returns>a boolean</returns>
	static bool IsKeyJustPressed(int key);

	/// <summary>
	/// Returns true if the specified key was just released during the previous frame.
	/// </summary>
	/// <param name="key"></param>
	/// <returns>a boolean</returns>
	static bool IsKeyJustReleased(int key);

	/// <summary>
	/// Do not call this function outside of the Engine.
	/// Intended to be called once at the end of the update and rendering steps of a frame, at the very end of the Engine's loop.
	/// </summary>
	static void ResetJustChanged();

	/// <summary>
	/// Enum shortcuts for different keys on the keyboard supported by glfw.
	/// </summary>
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
		ESC = GLFW_KEY_ESCAPE,
		SPACE = GLFW_KEY_SPACE
	};

private:
	static bool keys[];
	static bool justChanged[];
	
};

#endif