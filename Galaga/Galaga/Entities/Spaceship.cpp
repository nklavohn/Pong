#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"

Spaceship::Spaceship() : Entity(Vector2(30, 30), SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31)))
{
	speed = 100;
	rotSpeed = 250;
	currentSprite = IVector2(1, 0);
	vel = Vector2::JHAT;
	spriteSheet.SetRotCenter(Vector2(12, 7));
}

Spaceship::~Spaceship()
{

}

void Spaceship::Move()
{
	
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		pos += vel * Engine::GetDeltaTime() * speed;
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rot += deltaRot;
		vel.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{
		pos -= vel * Engine::GetDeltaTime() * speed;
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
	spriteSheet.RenderRelativeTo(pos, rot, currentSprite);
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
	DebugPhysicsDefault();
}

Vector2 Spaceship::GetPos() const
{
	return pos;
}