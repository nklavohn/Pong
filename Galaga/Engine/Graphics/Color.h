#ifndef ENGINE_COLOR
#define ENGINE_COLOR

/// <summary>
/// Holds four floats in the domain [0, 1] representing the r, g, b, a channels of a color.
/// </summary>
class Color {

public:
	Color();
	Color(const float& gray, const float& _a);
	Color(const float& _r, const float& _g, const float& _b, const float& _a);
	~Color();

	/// <summary>
	/// Returns the average of the two colors, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Average(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Returns the two colors multiplied together, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Multiply(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Returns the sum of the two colors, constraining channels to a max of 1, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Add(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Returns the difference of Color a - Color b, constraining channels to a min of 0, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Subtract(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Returns the Color whose channels are the max of the channels of the two colors given, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Max(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Returns the Color whose channels are the min of the channels of the two colors given, with alpha = 1 as default.
	/// </summary>
	/// <param name="includeAlpha">false by default, if true, averages the alpha channel as well</param>
	/// <returns>a Color</returns>
	static Color Min(const Color& a, const Color& b, bool includeAlpha = false);

	/// <summary>
	/// Converts the color to grayscale by averaging the rgb values together, retaining the alpha value by default.
	/// </summary>
	/// <param name="retainAlpha">true by default. if true, retains alpha channel value, otherwise, sets alpha to 1</param>
	/// <returns>a Color</returns>
	static Color ToGrayscale(const Color& c, bool retainAlpha = true);

	float r;
	float g;
	float b;
	float a;

	static const Color RED;
	static const Color ORANGE;
	static const Color YELLOW;
	static const Color GREEN;
	static const Color CYAN;
	static const Color BLUE;
	static const Color MAGENTA;
	static const Color WHITE;
	static const Color BLACK;
	static const Color LIGHT_GRAY;
	static const Color GRAY;
	static const Color DARK_GRAY;

private:
	void Initialize(const float& _r, const float& _g, const float& _b, const float& _a);
};


#endif