#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"

Spaceship::Spaceship(const Vector2& pos) : Entity(SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31)))
{
	speed = 200;
	rotSpeed = 250;
	currentSprite = IVector2(1, 0);
	vel = Vector2::JHAT;
	spriteSheet.SetRotCenter(Vector2(10.5, 13));
	cDetector = new CircHitbox(pos, 10);
}

Spaceship::~Spaceship()
{

}

void Spaceship::Move()
{
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		cDetector->AddToCenter(vel * Engine::GetDeltaTime() * speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rot += deltaRot;
		vel.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{
		cDetector->AddToCenter(vel.Flip(false) * Engine::GetDeltaTime() * speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::D))
	{
		float deltaRot = -rotSpeed * Engine::GetDeltaTime();
		rot += deltaRot;
		vel.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::E))
	{
		
	}
	if (Keyboard::IsKeyPressed(Keyboard::Q))
	{

	}
}

void Spaceship::Shoot()
{
	shotCooldown -= Engine::GetDeltaTime();

	if (Mouse::IsButtonJustPressed(Mouse::LEFT) && shotCooldown <= 0)
	{
	
	}
}

void Spaceship::Render() const
{
	spriteSheet.RenderRelativeTo(cDetector->GetCenter(), rot, currentSprite);
}

bool Spaceship::IsHit()
{
	return true;
}

void Spaceship::Respawn()
{

}

void Spaceship::DebugPhysics() const
{
	if (cDetector)
	{
		cDetector->Render(Color::WHITE);
		Vector2 pos = cDetector->GetCenter();
		ShapeRenderer::DrawVector(Color::WHITE, pos, pos + vel * 10);
	}
}

Vector2 Spaceship::GetPos() const
{
	return cDetector->GetCenter();
}