#include "Camera.h"

#include "Engine/Engine.h"

float Camera::pixelsPerMeter = 1;
Vector2 Camera::dim = Vector2(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT) / Engine::SCALE;
Vector2 Camera::pos = Camera::dim / 2;

Vector2 Camera::ToPixels(Vector2 v_meters)
{
	return v_meters * pixelsPerMeter;
}

Vector4 Camera::ToPixels(Vector4 v_meters)
{
	return v_meters * pixelsPerMeter;
}

Vector2 Camera::ToMeters(Vector2 v_pixels)
{
	return v_pixels / pixelsPerMeter;
}

Vector4 Camera::ToMeters(Vector4 v_pixels)
{
	return v_pixels / pixelsPerMeter;
}

Vector2 Camera::ToDisplayCoords(Vector2 v_worldCoord, int unitConversion)
{
	switch (unitConversion)
	{
	case (F_PIXEL_TO_PIXELS):
		return v_worldCoord + (pos * pixelsPerMeter);

	case (F_PIXEL_TO_METERS):
		return (v_worldCoord / pixelsPerMeter) + pos;

	case (F_METER_TO_PIXELS):
		return (v_worldCoord + pos) * pixelsPerMeter;

	case (F_METER_TO_METERS):
		return v_worldCoord + pos;

	default:
		std::cout << "Invalid unitConversion passed to Camera.ToDisplayCoords()" << std::endl;
		return v_worldCoord;
	}
}

Vector4 Camera::ToDisplayCoords(Vector4 v_worldCoord, int unitConversion)
{
	Vector4 pos2 = Vector4(pos, pos);  //copy pos twice into Vector4 to move both points inside input v
	switch (unitConversion)
	{
	case (F_PIXEL_TO_PIXELS):
		return v_worldCoord + (pos2 * pixelsPerMeter);

	case (F_PIXEL_TO_METERS):
		return (v_worldCoord / pixelsPerMeter) + pos2;

	case (F_METER_TO_PIXELS):
		return (v_worldCoord + pos2) * pixelsPerMeter;

	case (F_METER_TO_METERS):
		return v_worldCoord + pos2;

	default:
		std::cout << "Invalid unitConversion passed to Camera.ToDisplayCoords()" << std::endl;
		return v_worldCoord;
	}
}

Vector2 Camera::ToWorldCoords(Vector2 v_displayCoord, int unitConversion)
{
	switch (unitConversion)
	{
	case (F_PIXEL_TO_PIXELS):
		return v_displayCoord - (pos * pixelsPerMeter);

	case (F_PIXEL_TO_METERS):
		return (v_displayCoord / pixelsPerMeter) - pos;

	case (F_METER_TO_PIXELS):
		return (v_displayCoord - pos) * pixelsPerMeter;

	case (F_METER_TO_METERS):
		return v_displayCoord - pos;

	default:
		std::cout << "Invalid unitConversion passed to Camera.To'WorldCoords()" << std::endl;
		return v_displayCoord;
	}
}

Vector4 Camera::ToWorldCoords(Vector4 v_displayCoord, int unitConversion)
{
	Vector4 pos2 = Vector4(pos, pos);  //copy pos twice into Vector4 to move both points inside input v
	switch (unitConversion)
	{
	case (F_PIXEL_TO_PIXELS):
		return v_displayCoord - (pos2 * pixelsPerMeter);

	case (F_PIXEL_TO_METERS):
		return (v_displayCoord / pixelsPerMeter) - pos2;

	case (F_METER_TO_PIXELS):
		return (v_displayCoord - pos2) * pixelsPerMeter;

	case (F_METER_TO_METERS):
		return v_displayCoord - pos2;

	default:
		std::cout << "Invalid unitConversion passed to Camera.To'WorldCoords()" << std::endl;
		return v_displayCoord;
	}
}