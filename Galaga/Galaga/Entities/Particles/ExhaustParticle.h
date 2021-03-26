#ifndef SPACEGAME_EXHAUSTPARTICLE
#define SPACEGAME_EXHAUSTPARTICLE

#include "Engine/Entities/Particle.h"

class ExhaustParticle : public Particle
{
public:
	ExhaustParticle();
	ExhaustParticle(const Vector2& _pos, const Vector2& _vel);
	
	//rule of three
	~ExhaustParticle();
	ExhaustParticle(const ExhaustParticle& other) : ExhaustParticle(other.hitbox->GetCenter(), other.vel) {}
	ExhaustParticle& operator=(const ExhaustParticle& other) { return *this;  }

	void Update() override;
	void Render() const override;
	void DebugPhysics() const override;

	std::shared_ptr<Entity> CloneEntity() const override { return std::make_shared<ExhaustParticle>(*this); }
	std::shared_ptr<Particle> CloneParticle() const override { return std::make_shared<ExhaustParticle>(*this); }

private:
	void Initialize();
};

#endif