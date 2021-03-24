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

	void Move() override;
	void Render() const override;
	void DebugPhysics() const override;

protected:
	ExhaustParticle* clone_impl() const override { return new ExhaustParticle(*this); }

private:
	void Initialize();
};

#endif