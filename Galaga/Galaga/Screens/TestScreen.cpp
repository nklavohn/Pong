#include "TestScreen.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Graphics/ShapeRenderer.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;
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
	sprite.RenderSprite(IVector2(1, 0));
	ShapeRenderer::StrokeBox(Color::CYAN, Vector4(10, 10, 100, 100));
	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}