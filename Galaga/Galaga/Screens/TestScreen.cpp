#include "TestScreen.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Math/Camera.h"

TestScreen::TestScreen(const IVector2& _dim) : Screen(_dim) 
{
	color = Color::DARK_GRAY;
}

TestScreen::~TestScreen() 
{

}

void TestScreen::Update() 
{
	ship.Move();
	Camera::Ease(ship.GetPos(), 20);
}

void TestScreen::Render() const
{
	BeginRender();
	Camera::RenderGrid(Color::GRAY, 20);
	ship.Render();

	ship.DebugPhysics();
	EndRender();
}

Screen* TestScreen::Clone() const
{
	return new TestScreen(*this);
}