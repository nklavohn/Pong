#include "TranslationalState.h"

#include "Engine/Engine.h"

TranslationalState::TranslationalState()
{
	Initialize(Vector2::ZERO, Vector2::ZERO, 1, false, 0, false);
}

TranslationalState::TranslationalState(const float& _mass, const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag)
{
	Initialize(Vector2::ZERO, Vector2::ZERO, _mass, _hasGravity, _dragCoeff, _hasDrag);
}

TranslationalState::TranslationalState(const Vector2& _pos, const Vector2& _vel, const float& _mass, 
									   const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag)
{
	Initialize(_pos, _vel, _mass, _hasGravity, _dragCoeff, _hasDrag);
}

TranslationalState::~TranslationalState()
{

}

void TranslationalState::Initialize(const Vector2& _pos, const Vector2& _vel, const float& _mass,
									const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag)
{
	pos = _pos;
	vel = _vel;
	accel = Vector2::ZERO;
	prevPos = _pos;
	prevVel = _vel;
	mass = _mass;
	hasGravity = _hasGravity;
	dragCoefficient = _dragCoeff;
	hasDrag = _hasDrag;

	forces = std::queue<Vector2>();
}

void TranslationalState::AddForce(const Vector2& force)
{
	forces.push(force);
}

void TranslationalState::Move()
{
	Vector2 netForce = Vector2::ZERO;
	while (!forces.empty())
	{
		netForce += forces.front();
		forces.pop();
	}

	accel = netForce / mass;
	float dt = Engine::GetDeltaTime();

	prevPos = pos;
	prevVel = vel;
	pos += vel * dt + accel * 0.5F * dt * dt;
	vel += accel * dt;
}

/*
bool TranslationalState2::HasDrag() const
{
	return hasDrag;
}

bool TranslationalState2::HasGravity() const
{
	return hasGravity;
}

void TranslationalState2::SetDragTo(const bool state)
{
	hasDrag = state;
}

void TranslationalState2::SetDragCoefficient(const float& dragCoeff)
{
	dragCoefficient = dragCoeff;
}

void TranslationalState2::SetGravityTo(const bool state)
{
	hasGravity = state;
}

Vector2 TranslationalState2::Pos() const
{ 
	return pos;
}

Vector2 TranslationalState2::Vel() const
{
	return vel;
}

Vector2 TranslationalState2::Accel() const
{
	return accel;
}

Vector2 TranslationalState2::PrevPos() const
{
	return prevPos;
}

Vector2 TranslationalState2::PrevVel() const
{
	return prevVel;
}

void TranslationalState2::SetPos(const Vector2& _pos)
{
	pos = _pos;
}

void TranslationalState2::SetVel(const Vector2& _vel)
{
	vel = _vel;
}*/