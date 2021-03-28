#include "RotationalState2.h"

#include "Engine/Engine.h"

RotationalState2::RotationalState2(const float& _rotInertia, const bool _hasDrag, const float& _dragCoeff)
{
	angle = 0;
	vel = 0;
	prevAngle = 0;
	prevVel = 0;
	rotInertia = _rotInertia;
	hasDrag = _hasDrag;
	dragCoefficient = _dragCoeff;

	moments = std::queue<float>();
}

RotationalState2::RotationalState2(const float& _angle, const float& _vel, const float& _rotInertia,
								   const bool _hasDrag, const float& _dragCoeff)
{
	angle = _angle;
	vel = _vel;
	prevAngle = _angle;
	prevVel = _vel;
	rotInertia = _rotInertia;
	hasDrag = _hasDrag;
	dragCoefficient = _dragCoeff;

	moments = std::queue<float>();
}

RotationalState2::~RotationalState2()
{

}

void RotationalState2::AddMoment(const float& moment)
{
	moments.push(moment);
}

void RotationalState2::Move()
{
	float netMoment = 0;
	while (!moments.empty())
	{
		netMoment += moments.front();
		moments.pop();
	}

	float accel = netMoment / rotInertia;
	float dt = Engine::GetDeltaTime();

	prevAngle = angle;
	prevVel = vel;
	angle += vel * dt + 0.5F * accel * dt * dt;
	vel += accel * dt;
}

bool RotationalState2::HasDrag() const
{
	return hasDrag;
}

void RotationalState2::SetDragTo(const bool state)
{
	hasDrag = state;
}

void RotationalState2::SetDragCoefficient(const float& dragCoeff)
{
	dragCoefficient = dragCoeff;
}