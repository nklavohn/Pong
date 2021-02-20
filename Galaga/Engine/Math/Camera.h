#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Vector2.h"
#include "Vector4.h"
#include <iostream>

class Camera
{
public:
	static Vector2 ToPixels(Vector2 v_meters);
	static Vector2 ToMeters(Vector2 v_pixels);
	static Vector2 ToDisplayCoords(Vector2 v_worldCoord, int unitConversion);
	static Vector2 ToWorldCoords(Vector2 v_displayCoord, int unitConversion);
	static Vector4 ToPixels(Vector4 v_meters);
	static Vector4 ToMeters(Vector4 v_pixels);
	static Vector4 ToDisplayCoords(Vector4 v_worldCoord, int unitConversion);
	static Vector4 ToWorldCoords(Vector4 v_displayCoord, int unitConversion);

	static const int F_PIXEL_TO_PIXELS = 0;
	static const int F_PIXEL_TO_METERS = 1;
	static const int F_METER_TO_PIXELS = 2;
	static const int F_METER_TO_METERS = 3;

private:
	static float pixelsPerMeter;
	static Vector2 pos;
	static Vector2 dim;
};

#endif
