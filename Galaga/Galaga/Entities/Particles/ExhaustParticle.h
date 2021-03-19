#ifndef SPACEGAME_EXHAUSTPARTICLE
#define SPACEGAME_EXHAUSTPARTICLE

#include "Engine/Entities/Particle.h"

class ExhaustParticle : public Particle
{
public:
	ExhaustParticle();
	ExhaustParticle(const Vector2& _pos, const Vector2& _vel);
	~ExhaustParticle();

	void Move() override;
	void Render() const override;
	void DebugPhysics() const override;

private:
	void Initialize();
};

#endif