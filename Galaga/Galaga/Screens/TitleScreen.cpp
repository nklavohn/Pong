#include "TitleScreen.h"
#include "GameScreen.h"
#include "Engine/Engine.h"
#include "Engine/IO/Keyboard.h"

TitleScreen::TitleScreen(const IVector2& _dim) : Screen(_dim) 
{
	color = Color(0.114, 0.114, 0.227, 1);
}

TitleScreen::~TitleScreen() 
{

}

void TitleScreen::Update() 
{
	if (Keyboard::IsKeyPressed(Keyboard::SPACE))
	{
		Screen* screen = nullptr;
		GameScreen s = GameScreen(Engine::windowPixelDim);
		screen = s.Clone();
		Engine::SetScreen(*screen);
	}
	else if (Keyboard::IsKeyPressed(Keyboard::ESC))
	{
		glfwSetWindowShouldClose(Engine::window, 1);
	}
}

void TitleScreen::Render() const
{
	BeginRender();
	title.RenderRelativeTo(Camera::GetDim() / 2);
	EndRender();
}

Screen* TitleScreen::Clone() const
{
	return new TitleScreen(*this);
}