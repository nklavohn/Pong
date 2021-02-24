#include "TestScreen.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Graphics/ShapeRenderer.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;
}

TestScreen::~TestScreen() {

}

void TestScreen::Update() {
	if (Mouse::IsButtonJustPressed(Mouse::LEFT))
	{
		Vector4 v1 = Vector4(2, 3, 7, 1);
		Vector4 v2 = Vector4(12, 0, 0, 0);

		Vector4 v3 = v1.ProjOnto(v2);
		cout << v3.ToString() << endl;

		/*float f = Vector4::Len2(v2);
		cout << f << endl;*/

	}

	/*if (Mouse::IsButtonPressed(Mouse::LEFT))
	{
		sprite.SetPos(Mouse::GetScaledMousePos());
	}*/
}

void TestScreen::Render() {
	BeginRender();
	sprite.RenderSprite(IVector2(1, 0));
	ShapeRenderer::StrokeBox(Color::CYAN, Vector4(10, 10, 100, 100));
	//ShapeRenderer::StrokeCircle(Color(0.6, 0.1, 0.4, 1), Vector2(50, 50), 20);
	ShapeRenderer::DrawCircle(Color(0.6, 0.1, 0.4, 1), Color::BLUE, Vector2(50, 50), 20, -1, 5);
	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}