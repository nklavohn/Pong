#include "Camera.h"

#include "Engine/Engine.h"

float Camera::pixelsPerMeter = 1;
Vector2 Camera::dim = Vector2(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT) / Engine::SCALE / pixelsPerMeter;
Vector2 Camera::pos = Camera::dim / 2;

float Camera::ToPixels(float f)
{
	return f * pixelsPerMeter;
}

Vector2 Camera::ToPixels(const Vector2& v_meters)
{
	return v_meters * pixelsPerMeter;
}

Vector4 Camera::ToPixels(const Vector4& v_meters)
{
	return v_meters * pixelsPerMeter;
}

float Camera::ToMeters(float f)
{
	return f / pixelsPerMeter;
}

Vector2 Camera::ToMeters(const Vector2& v_pixels)
{
	return v_pixels / pixelsPerMeter;
}

Vector4 Camera::ToMeters(const Vector4& v_pixels)
{
	return v_pixels / pixelsPerMeter;
}

Vector2 Camera::ToDisplayCoords(const Vector2& v_worldCoord, int unitConversion)
{
	switch (unitConversion)
	{
	case (F_PIXELS_TO_PIXELS):
		return v_worldCoord + (pos * pixelsPerMeter);

	case (F_PIXELS_TO_METERS):
		return (v_worldCoord / pixelsPerMeter) + pos;

	case (F_METERS_TO_PIXELS):
		return (v_worldCoord + pos) * pixelsPerMeter;

	case (F_METERS_TO_METERS):
		return v_worldCoord + pos;

	default:
		std::cout << "Invalid unitConversion passed to Camera.ToDisplayCoords()" << std::endl;
		return v_worldCoord;
	}
}

Vector4 Camera::ToDisplayCoords(const Vector4& v_worldCoord, int unitConversion)
{
	Vector4 pos2 = Vector4(pos, pos);  //copy pos twice into Vector4 to move both points inside input v
	switch (unitConversion)
	{
	case (F_PIXELS_TO_PIXELS):
		return v_worldCoord + (pos2 * pixelsPerMeter);

	case (F_PIXELS_TO_METERS):
		return (v_worldCoord / pixelsPerMeter) + pos2;

	case (F_METERS_TO_PIXELS):
		return (v_worldCoord + pos2) * pixelsPerMeter;

	case (F_METERS_TO_METERS):
		return v_worldCoord + pos2;

	default:
		std::cout << "Invalid unitConversion passed to Camera.ToDisplayCoords()" << std::endl;
		return v_worldCoord;
	}
}

Vector2 Camera::ToWorldCoords(const Vector2& v_displayCoord, int unitConversion)
{
	switch (unitConversion)
	{
	case (F_PIXELS_TO_PIXELS):
		return v_displayCoord - (pos * pixelsPerMeter);

	case (F_PIXELS_TO_METERS):
		return (v_displayCoord / pixelsPerMeter) - pos;

	case (F_METERS_TO_PIXELS):
		return (v_displayCoord - pos) * pixelsPerMeter;

	case (F_METERS_TO_METERS):
		return v_displayCoord - pos;

	default:
		std::cout << "Invalid unitConversion passed to Camera.To'WorldCoords()" << std::endl;
		return v_displayCoord;
	}
}

Vector4 Camera::ToWorldCoords(const Vector4& v_displayCoord, int unitConversion)
{
	Vector4 pos2 = Vector4(pos, pos);  //copy pos twice into Vector4 to move both points inside input v
	switch (unitConversion)
	{
	case (F_PIXELS_TO_PIXELS):
		return v_displayCoord - (pos2 * pixelsPerMeter);

	case (F_PIXELS_TO_METERS):
		return (v_displayCoord / pixelsPerMeter) - pos2;

	case (F_METERS_TO_PIXELS):
		return (v_displayCoord - pos2) * pixelsPerMeter;

	case (F_METERS_TO_METERS):
		return v_displayCoord - pos2;

	default:
		std::cout << "Invalid unitConversion passed to Camera.To'WorldCoords()" << std::endl;
		return v_displayCoord;
	}
}

Vector4 Camera::GetVisibleBounds()
{
	return Vector4(pos - dim / 2, pos + dim / 2);
}

void Camera::Ease(const Vector2& _pos, const float& easeDist)
{
	Vector2 screenCenter = ToWorldCoords(Vector2(Engine::SCREEN_WIDTH / Engine::SCALE, Engine::SCREEN_HEIGHT / Engine::SCALE) / 2, Camera::F_PIXELS_TO_METERS);
	Vector2 diff = _pos - screenCenter;
	std::cout << diff.ToString() << std::endl;
	if (diff.Len2() > easeDist * easeDist)
	{
		pos -= diff * Engine::GetDeltaTime();
	}
}