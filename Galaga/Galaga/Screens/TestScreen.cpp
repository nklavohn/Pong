#include "TestScreen.h"
#include "Engine/IO/Mouse.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;
	sprite = Sprite("Galaga/Assets/ship.png");
}

TestScreen::~TestScreen() {

}

void TestScreen::Update() {
	if (Mouse::IsButtonPressed(Mouse::LEFT))
	{
		sprite.SetPos(Mouse::GetScaledMousePos());
	}
}

void TestScreen::Render() {
	BeginRender();
	sprite.Render();
	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}