#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"

Spaceship::Spaceship(const Vector2& pos) : Entity(PLAYER, SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31)))
{
	speed = 200;
	rotSpeed = 250;
	currentSprite = IVector2(1, 0);
	vel = Vector2::JHAT;
	spriteSheet.SetRotCenter(Vector2(10.5, 13));
	hitbox = new CircHitbox(pos, 10);
}

Spaceship::~Spaceship()
{

}

void Spaceship::Move()
{
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		hitbox->AddToCenter(vel * Engine::GetDeltaTime() * speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rot += deltaRot;
		vel.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{
		hitbox->AddToCenter(vel.Flip(false) * Engine::GetDeltaTime() * speed);
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
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), rot, currentSprite);
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
	if (hitbox)
	{
		hitbox->Render(Color::WHITE);
		Vector2 pos = hitbox->GetCenter();
		ShapeRenderer::DrawVector(Color::WHITE, pos, pos + vel * 10);
	}
}

Vector2 Spaceship::GetPos() const
{
	return hitbox->GetCenter();
}