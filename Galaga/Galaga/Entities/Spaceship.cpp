#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"

Spaceship::Spaceship() : Entity(Vector2(30, 30), SpriteSheet("Galaga/Assets/ship.png", IVector2(21, 31)))
{
	speed = 100;
}

Spaceship::~Spaceship()
{

}

void Spaceship::Move()
{
	dir = Vector2::ZERO;

	if (Keyboard::IsKeyPressed(Keyboard::W)) dir += Vector2::JHAT;
	if (Keyboard::IsKeyPressed(Keyboard::A)) dir -= Vector2::IHAT;
	if (Keyboard::IsKeyPressed(Keyboard::S)) dir -= Vector2::JHAT;
	if (Keyboard::IsKeyPressed(Keyboard::D)) dir += Vector2::IHAT;

	if (dir != Vector2::ZERO)
	{
		dir = dir.Unitize();
		pos += dir * speed * Engine::GetDeltaTime();
	}

	Vector2::Constrain(&pos, 
					  posMins.x, 
					  Engine::SCREEN_WIDTH / Engine::SCALE - posMaxs.x, 
					  posMaxs.y, 
					  Engine::SCREEN_HEIGHT / Engine::SCALE - posMaxs.y);
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
	if (dir.x == 0) spriteSheet.RenderRelativeTo(pos, STRAIGHT);
	else if (dir.x < 0) spriteSheet.RenderRelativeTo(pos, LEFT);
	else spriteSheet.RenderRelativeTo(pos, RIGHT);
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
