#include "TestScreen.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;
}

TestScreen::~TestScreen() {

}

void TestScreen::Update() {

}

void TestScreen::Render() {
	BeginRender();

	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}