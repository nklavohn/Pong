#ifndef ENGINE_SHAPERENDERER
#define ENGINE_SHAPERENDERER

#include "Engine/Graphics/Color.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

/// <summary>
/// Renders shapes from primatives (lines and triangles).
/// </summary>
class ShapeRenderer
{
public:
	/// <summary>
	/// Draws a line between the two specified points, by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void DrawLine(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Draws a line between as specified by Vector4(p1, p2), by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void DrawLine(const Color& c, const Vector4& line, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Draws an arrow from the tail to the head, by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void DrawVector(const Color& c, const Vector2& head, const Vector2& tail, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Outlines the box bound by p1 and p2 at opposite corners, by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void StrokeBox(const Color& c, const Vector2& p1, const Vector2& p2, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Outlines the box represented by Vector4(p1, p2), by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void StrokeBox(const Color& c, const Vector4& box, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Fills the box represented by p1 and p2 at opposite corners, by default in world coordinates in meters
	/// </summary>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void FillBox(const Color& c, const Vector2& p1, const Vector2& p2, bool convertToDisplayPos=true);

	/// <summary>
	/// Fills the box represented by Vector4(p1, p2), by default in world coordinates in meters
	/// </summary>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void FillBox(const Color& c, const Vector4& box, bool convertToDisplayPos=true);

	/// <summary>
	/// Outlines and fills (in corresponding colors) the box bound by p1 and p2 at opposite corners, by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters,
	///  if false treats input as display coordinates in pixels</param>
	static void DrawBox(const Color& fill, const Color& stroke, const Vector2& p1, const Vector2& p2, float lineWidth=2, bool convertToDisplayPos=true);
	
	/// <summary>
	/// Outlines and fills (in corresponding colors) the box bound by Vector4(p1, p2), by default in world coordinates in meters
	/// </summary>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters,
	///  if false treats input as display coordinates in pixels</param>
	static void DrawBox(const Color& fill, const Color& stroke, const Vector4& box, float lineWidth=2, bool convertToDisplayPos=true);

	/// <summary>
	/// Outlines the circle with center c and radius r, by default in world coordinates in meters
	/// </summary>
	/// <param name="sides">specify number of sides to approximate circle. By default, determines appropriate 
	/// number of sides to keep side length reasonable, to a minimum of CIRC_MIN_SIDES</param>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters,
	///  if false treats input as display coordinates in pixels</param>
	static void StrokeCircle(const Color& c, const Vector2& center, float r, float sides=-1, float linewidth=2, bool convertToDisplayPos=true);
	
	/// <summary>
	/// Fills the circle with center c and radius r, by default in world coordinates in meters
	/// </summary>
	/// <param name="sides">specify number of sides to approximate circle. By default, determines appropriate 
	/// number of sides to keep side length reasonable, to a minimum of CIRC_MIN_SIDES</param>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void FillCircle(const Color& c, const Vector2& center, float r, float sides=-1, bool convertToDisplayPos=true);
	
	/// <summary>
	/// Outlines and fills (in corresponding colors) the circle with center c and radius r, 
	/// by default in world coordinates in meters
	/// </summary>
	/// <param name="sides">specify number of sides to approximate circle. By default, determines appropriate number 
	/// of sides to keep side length reasonable, to a minimum of CIRC_MIN_SIDES</param>
	/// <param name="lineWidth">equals 2 by default</param>
	/// <param name="convertToDisplayPos">true by default, if true treats input as world coordinates in meters, 
	/// if false treats input as display coordinates in pixels</param>
	static void DrawCircle(const Color& fill, const Color& stroke, const Vector2& center, float r, float sides=-1, float linewidth=2, bool convertToDisplayPos=true);

private:
	static void VectorHelper(const Vector2& p1, const Vector2& p2);
	static void LineHelper(const Vector2& p1, const Vector2& p2);
	static void BoxHelper(const Vector2& p1, const Vector2& p2);
	static void CircleHelper(const Vector2& center, float r, float sides);

	/// <summary>
	/// Called at the beginning of a shape draw for strokes
	/// </summary>
	static void Start(const Color& c, float lineWidth);

	/// <summary>
	/// Called at the beginning of a shape draw for fills
	/// </summary>
	static void Start(const Color& c);

	/// <summary>
	/// Called at the end of a shape draw.
	/// </summary>
	static void End();

	/// <summary>
	/// Converts from world position in meters to display position in pixels
	/// </summary>
	/// <returns>a Vector2</returns>
	static Vector2 ConvertCoords(const Vector2& v);

	/// <summary>
	/// Converts from world position in meters to display position in pixels
	/// </summary>
	/// <returns>a Vector4</returns>
	static Vector4 ConvertCoords(const Vector4& v);
};

#endif