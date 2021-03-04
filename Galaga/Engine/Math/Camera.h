#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Vector2.h"
#include "Vector4.h"
#include <iostream>

class Camera
{
public:
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

	static Vector4 GetVisibleBounds();

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
