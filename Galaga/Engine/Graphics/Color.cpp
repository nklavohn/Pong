#include "Color.h"

Color::Color() {
	Initialize(0, 0, 0, 1);
}

Color::Color(float gray, float _a) {
	Initialize(gray, gray, gray, _a);
}

Color::Color(float _r, float _g, float _b, float _a) {
	Initialize(_r, _g, _b, _a);
}

void Color::Initialize(float _r, float _g, float _b, float _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Color::~Color() {

}

const Color Color::RED = Color(1, 0, 0, 1);
const Color Color::YELLOW = Color(1, 1, 0, 1);
const Color Color::GREEN = Color(0, 1, 0, 1);
const Color Color::CYAN = Color(0, 1, 1, 1);
const Color Color::BLUE = Color(0, 0, 1, 1);
const Color Color::MAGENTA = Color(1, 0, 1, 1);
const Color Color::WHITE = Color(1, 1);
const Color Color::BLACK = Color(0, 1);
const Color Color::LIGHT_GRAY = Color(0.75, 1);
const Color Color::DARK_GRAY = Color(0.25, 1);