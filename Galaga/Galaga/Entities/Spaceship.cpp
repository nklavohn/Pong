#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"

#include "Galaga/Entities/Particles/ExhaustParticle.h"

Spaceship::Spaceship() : Player(std::unique_ptr<Hitbox>(new CircHitbox(Vector2::ZERO, 10))),
	ConstantParticleEmitter(std::unique_ptr<Particle>(new ExhaustParticle()), 0.05F)
{
	speed = 200;
	rotSpeed = 250;
	currentSprite = IVector2(1, 0);
	velDir = Vector2::JHAT;
	spriteSheet.SetRotCenter(Vector2(10.5F, 13));

	class PhotoCannon : public InputParticleEmitter
	{
	public:
		PhotoCannon(std::unique_ptr<Particle> _particle, const float& _cooldown) : InputParticleEmitter(std::move(_particle), _cooldown) {};
		bool Input() const override
		{
			return Keyboard::IsKeyPressed(Keyboard::SPACE);
		}
	};
	photonCannon = std::unique_ptr<InputParticleEmitter>(new PhotoCannon(std::unique_ptr<Particle>(new ExhaustParticle()), 0.5F));
}

Spaceship::~Spaceship()
{

}

void Spaceship::Update()
{
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		tState.pos += velDir * Engine::GetDeltaTime() * speed;
		hitbox->SetCenter(tState.pos);
		EmitParticles(tState.pos, velDir * -speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rState.angle += deltaRot;
		velDir.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{
		
	}
	if (Keyboard::IsKeyPressed(Keyboard::D))
	{
		float deltaRot = -rotSpeed * Engine::GetDeltaTime();
		rState.angle += deltaRot;
		velDir.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::E))
	{
		
	}
	if (Keyboard::IsKeyPressed(Keyboard::Q))
	{

	}

	photonCannon->EmitParticles(tState.pos, velDir * speed * 5);
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
	spriteSheet.RenderRelativeTo(tState.pos, rState.angle, currentSprite);
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
	hitbox->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::WHITE, tState.pos, tState.pos + velDir * 10);
}

Vector2 Spaceship::GetPos() const
{
	return hitbox->GetCenter();
}