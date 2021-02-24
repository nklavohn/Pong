#include "Color.h"
#include <algorithm>

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

Color Color::Average(const Color& a, const Color& b)
{
	return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2, (a.a + b.a) / 2);
}

Color Color::Multiply(const Color& a, const Color& b)
{
	return Color(a.r * b.r, a.g * b.g, a.b * b.b, a.a * b.a);
}

Color Color::Add(const Color& a, const Color& b)
{
	return Color(std::min(a.r + b.r, 1.0F), std::min(a.g + b.g, 1.0F), std::min(a.b + b.b, 1.0F), std::min(a.a + b.a, 1.0F));
}

Color Color::Subtract(const Color& a, const Color& b)
{

}

Color Color::Max(const Color& a, const Color& b)
{

}

Color Color::Min(const Color& a, const Color& b)
{

}

Color ToGrayscale(const Color& c)
{

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