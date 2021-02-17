#include "Color.h"

Color::Color() {
	Color(0, 0, 0, 1);
}

Color::Color(float gray, float _a) {
	Color(gray, gray, gray, _a);
}

Color::Color(float _r, float _g, float _b, float _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Color::~Color() {

}

const Color RED = Color(1, 0, 0, 1);
const Color YELLOW = Color(1, 1, 0, 1);
const Color GREEN = Color(0, 1, 0, 1);
const Color CYAN = Color(0, 1, 1, 1);
const Color BLUE = Color(0, 0, 1, 1);
const Color MAGENTA = Color(1, 0, 1, 1);
const Color WHITE = Color(1, 1);
const Color BLACK = Color(0, 1);
const Color LIGHT_GRAY = Color(0.75, 1);
const Color DARK_GRAY = Color(0.25, 1);