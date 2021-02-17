#ifndef ENGINE_COLOR
#define ENGINE_COLOR

class Color {

public:
	Color();
	Color(float gray, float _a);
	Color(float _r, float _g, float _b, float _a);
	~Color();

	float r;
	float g;
	float b;
	float a;

	static const Color RED;
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
	void Initialize(float _r, float _g, float _b, float _a);
};


#endif