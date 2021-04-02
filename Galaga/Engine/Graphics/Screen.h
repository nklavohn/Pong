#ifndef ENGINE_SCREEN
#define ENGINE_SCREEN

#include "GLFW/glfw3.h"
#include "Color.h"
#include "Engine/Math/IVector2.h"

/// <summary>
/// Holds the core update and render loops for a specific functionality of the game. Common implementations would be "TitleScreen, LoadingScreen, GameScreen, CreditScreen, etc."
/// </summary>
class Screen {

public:
	Screen();
	Screen(const IVector2& _dim);
	virtual ~Screen();

	/// <summary>
	/// Updates everything on the screen according to its changes during the previous frame
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// Renders everything onto the screen. No values can be changed within this method.
	/// </summary>
	virtual void Render() const = 0;

	/// <summary>
	/// Returns a pointer to a clone of the screen
	/// </summary>
	/// <returns>a Screen*</returns>
	virtual Screen* Clone() const = 0;

	/// <summary>
	/// Returns the width of the screen in pixels.
	/// </summary>
	/// <returns>an int</returns>
	int GetWidth() const;

	/// <summary>
	/// Returns the height of the screen in pixels.
	/// </summary>
	/// <returns>an int</returns>
	int GetHeight() const;

	/// <summary>
	/// Returns an IVector2 containing the dimensions of the screen in pixels.
	/// </summary>
	/// <returns>an int</returns>
	IVector2 GetDim() const;

	/// <summary>
	/// Sets the dimensions of the screen in pixels. This is meant to be called when the window is resized.
	/// </summary>
	/// <returns>an int</returns>
	void SetDim(const IVector2& _dim);

protected:
	IVector2 dim;

	Color color;

	/// <summary>
	/// Called at the beginning of the Render function
	/// </summary>
	void BeginRender() const;

	/// <summary>
	/// Called at the end of the Render function
	/// </summary>
	void EndRender() const;
};

#endif