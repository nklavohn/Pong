#include "TestScreen.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Graphics/ShapeRenderer.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;

	std::cout << box1.GetBox().ToString() << std::endl;
	std::cout << box2.GetBox().ToString() << std::endl;
}

TestScreen::~TestScreen() {

}

void TestScreen::Update() {
	std::cout << "-----------------" << std::endl;
	point1.SetCenter(Mouse::GetWorldPos());

	//if (box1.IsCollidingWith(&circ1))
	if (circ2.IsCollidingWith(&point1))
		//std::cout << box2.GetBox().ToString() << std::endl;
		std::cout << "Colliding!" << std::endl;
}

void TestScreen::Render() {
	BeginRender();
	
	box1.Render(Color::BLUE);
	box2.Render(Color::RED);
	circ1.Render(Color::MAGENTA);
	circ2.Render(Color::ORANGE);
	point1.Render(Color::CYAN);

	ShapeRenderer::DrawVector(Color::YELLOW, Vector2(0, 0), Vector2(15, 15));

	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}