#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Vector2.h"
#include "Vector4.h"
#include <iostream>
#include "Engine/Graphics/Color.h"

/// <summary>
/// Responsible for all conversions between world coordinates and display coordinates for seamless scaling and translation
/// of the view of the world. Also responsible for all unit conversions between meters and pixels.
/// </summary>
class Camera
{
public:
	//TODO replace this with an enum
	static const int F_PIXELS_TO_PIXELS = 0;
	static const int F_PIXELS_TO_METERS = 1;
	static const int F_METERS_TO_PIXELS = 2;
	static const int F_METERS_TO_METERS = 3;
	static const int PIXELS = 4;
	static const int METERS = 5;

	/// <summary>
	/// Converts the input from meters to pixels
	/// </summary>
	/// <returns>a float</returns>
	static float ToPixels(float v_meters);

	/// <summary>
	/// Converts the input from pixels to meters
	/// </summary>
	/// <returns>a float</returns>
	static float ToMeters(float v_pixels);

	/// <summary>
	/// Converts the input from meters to pixels
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 ToPixels(const Vector2& v_meters);

	/// <summary>
	/// Converts the input from pixels to meters
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 ToMeters(const Vector2& v_pixels);

	/// <summary>
	/// Converts the input from meters to pixels
	/// </summary>
	/// <returns>a Vector4</returns>
	static Vector4 ToPixels(const Vector4& v_meters);

	/// <summary>
	/// Converts the input from pixels to meters
	/// </summary>
	/// <returns>a Vector4</returns>
	static Vector4 ToMeters(const Vector4& v_pixels);

	/// <summary>
	/// Converts the world coordinate to a display coordinate, with the specified unit conversion
	/// </summary>
	/// <param name="unitConversion">specify one of: { F_PIXELS_TO_METERS, F_PIXELS_TO_PIXELS, F_METERS_TO_METERS, F_METERS_TO_PIXELS }</param>
	/// <returns>a Vector2</returns>
	static Vector2 ToDisplayCoords(const Vector2& v_worldCoord, const int& unitConversion);

	/// <summary>
	/// Converts the display coordinate to a world coordinate, with the specified unit conversion
	/// </summary>
	/// <param name="unitConversion">specify one of: { F_PIXELS_TO_METERS, F_PIXELS_TO_PIXELS, F_METERS_TO_METERS, F_METERS_TO_PIXELS }</param>
	/// <returns>a Vector2</returns>
	static Vector2 ToWorldCoords(const Vector2& v_displayCoord, const int& unitConversion);
	
	/// <summary>
	/// Converts the pair display coordinates Vector4(p1, p2) to a pair of world coordinates Vector4(p1, p2), with the specified unit conversion
	/// </summary>
	/// <param name="unitConversion">specify one of: { F_PIXELS_TO_METERS, F_PIXELS_TO_PIXELS, F_METERS_TO_METERS, F_METERS_TO_PIXELS }</param>
	/// <returns>a Vector4</returns>
	static Vector4 ToDisplayCoords(const Vector4& v_worldCoord, const int& unitConversion);
	
	/// <summary>
	/// Converts the pair display coordinates Vector4(p1, p2) to a pair of world coordinates Vector4(p1, p2), with the specified unit conversion
	/// </summary>
	/// <param name="unitConversion">specify one of: { F_PIXELS_TO_METERS, F_PIXELS_TO_PIXELS, F_METERS_TO_METERS, F_METERS_TO_PIXELS }</param>
	/// <returns>a Vector4</returns>
	static Vector4 ToWorldCoords(const Vector4& v_displayCoord, const int& unitConversion);

	/// <summary>
	/// Calculates the boundaries of the world visible on screen, in world coordinates.
	/// In other words, finds what world coordinates correspond to the display coordinates (0,0) and (screen_width, screen_height)
	/// </summary>
	/// <param name="units">by default in METERS, specify one of: { PIXELS, METERS }</param>
	/// <returns>a Vector4</returns>
	static Vector4 GetVisibleBounds(const int& units = METERS);

	/// <summary>
	/// Returns the dimension, in meters, of the screen
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 GetDim();

	/// <summary>
	/// Sets the dimension of the screen (given in pixels)
	/// </summary>
	/// <param name="_dim"></param>
	static void SetDim(const Vector2& _dim);

	/// <summary>
	/// Eases the camera focus towards the world coordinate given in meters.
	/// Default easing speed is equal to the error between camera's focus and given location, divided by 1 second.
	/// </summary>
	/// <param name="_pos">the position to ease towards, in world coordinates in meters</param>
	/// <param name="easeDist">the distance, in meters, beyond which the camera should be adjusted (its like a padding)</param>
	/// <param name="speedMult">multiplier to speed up or slow down the easing</param>
	static void Ease(const Vector2& _pos, const float& easeDist, const float& speedMult);

	/// <summary>
	/// Renders a grid with the declared spacing and color, bolding every fifth gridline.
	/// </summary>
	/// <param name="units">by default in METERS, specify one of: { PIXELS, METERS }</param>
	static void RenderGrid(const Color& c, const float& spacing, const int& units=METERS);


private:
	static float pixelsPerMeter;
	static Vector2 pos;  //vector from bottom left corner of screen to (0, 0) in meters
	static Vector2 dim;  //dimension, in meters, of the screen

	static void RenderGridHelper(const Color& c, const float& spacing);
};

#endif
