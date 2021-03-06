#ifndef ENGINE_CAMERA
#define ENGINE_CAMERA

#include "Vector2.h"
#include "Vector4.h"
#include <iostream>
#include "Engine/Graphics/Color.h"

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

	//unit and coordinate system conversions
	static float ToPixels(float v_meters);
	static float ToMeters(float v_pixels);

	static Vector2 ToPixels(const Vector2& v_meters);
	static Vector2 ToMeters(const Vector2& v_pixels);
	static Vector2 ToDisplayCoords(const Vector2& v_worldCoord, const int& unitConversion);
	static Vector2 ToWorldCoords(const Vector2& v_displayCoord, const int& unitConversion);
	
	static Vector4 ToPixels(const Vector4& v_meters);
	static Vector4 ToMeters(const Vector4& v_pixels);
	static Vector4 ToDisplayCoords(const Vector4& v_worldCoord, const int& unitConversion);
	static Vector4 ToWorldCoords(const Vector4& v_displayCoord, const int& unitConversion);

	//attributes
	static Vector4 GetVisibleBounds(const int& units=METERS);
	static void SetDim(const Vector2& _dim);

	//camera movement
	static void Ease(const Vector2& _pos, const float& easeDist);

	//camera display
	static void RenderGrid(const Color& c, const float& spacing, const int& units=METERS);


private:
	static float pixelsPerMeter;
	static Vector2 pos;  //vector from bottom left corner of screen to (0, 0) in meters
	static Vector2 dim;  //dimension, in meters, of the screen

	static void RenderGridHelper(const Color& c, const float& spacing);
};

#endif
