#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Vector2.h"
#include "Vector4.h"
#include <iostream>

class Camera
{
public:
	//unit and coordinate system conversions
	static float ToPixels(float v_meters);
	static float ToMeters(float v_pixels);

	static Vector2 ToPixels(const Vector2& v_meters);
	static Vector2 ToMeters(const Vector2& v_pixels);
	static Vector2 ToDisplayCoords(const Vector2& v_worldCoord, int unitConversion);
	static Vector2 ToWorldCoords(const Vector2& v_displayCoord, int unitConversion);
	
	static Vector4 ToPixels(const Vector4& v_meters);
	static Vector4 ToMeters(const Vector4& v_pixels);
	static Vector4 ToDisplayCoords(const Vector4& v_worldCoord, int unitConversion);
	static Vector4 ToWorldCoords(const Vector4& v_displayCoord, int unitConversion);

	//attributes
	static Vector4 GetVisibleBounds();

	//camera movement
	static void Ease(const Vector2& _pos, const float& easeDist);

	//TODO replace this with an enum
	static const int F_PIXELS_TO_PIXELS = 0;
	static const int F_PIXELS_TO_METERS = 1;
	static const int F_METERS_TO_PIXELS = 2;
	static const int F_METERS_TO_METERS = 3;

private:
	static float pixelsPerMeter;
	static Vector2 pos;  //vector from bottom left corner of screen to (0, 0) in meters
	static Vector2 dim;  //dimension, in meters, of the screen
};

#endif
