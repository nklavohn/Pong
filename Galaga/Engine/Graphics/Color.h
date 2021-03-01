#ifndef ENGINE_COLOR
#define ENGINE_COLOR

class Color {

public:
	Color();
	Color(const float& gray, const float& _a);
	Color(const float& _r, const float& _g, const float& _b, const float& _a);
	~Color();

	static Color Average(const Color& a, const Color& b, bool includeAlpha = false);
	static Color Multiply(const Color& a, const Color& b, bool includeAlpha = false);
	static Color Add(const Color& a, const Color& b, bool includeAlpha = false);
	static Color Subtract(const Color& a, const Color& b, bool includeAlpha = false);
	static Color Max(const Color& a, const Color& b, bool includeAlpha = false);
	static Color Min(const Color& a, const Color& b, bool includeAlpha = false);
	static Color ToGrayscale(const Color& c, bool includeAlpha = false);

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
	static const Color DARK_GRAY;

private:
	void Initialize(const float& _r, const float& _g, const float& _b, const float& _a);
};


#endif