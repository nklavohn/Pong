#ifndef ENGINE_INPUTEMITTER
#define ENGINE_INPUTEMITTER

#include "Emitter.h"
#include "Engine/Engine.h"

template <class T>
class InputEmitter : public Emitter<T>
{
public:
	InputEmitter(std::unique_ptr<T> _t, const float& _cooldown);
	InputEmitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~InputEmitter();

	virtual bool Input() const = 0;
	void Emit(const Vector2& pos, const Vector2& vel) override;

};

template <class T>
InputEmitter<T>::InputEmitter(std::unique_ptr<T> _t, const float& _cooldown) : Emitter<T>(std::move(_t), _cooldown)
{

}

template <class T>
InputEmitter<T>::InputEmitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue)
	: Emitter<T>(std::move(_t), _cooldown, sQueue)
{

}

template <class T>
InputEmitter<T>::~InputEmitter()
{

}

template <class T>
void InputEmitter<T>::Emit(const Vector2& pos, const Vector2& vel)
{
	remainingTime -= Engine::GetDeltaTime();

	if (Input() && remainingTime < 0)
	{
		std::shared_ptr<T> newT = particle->CloneEntity();
		newT->SetPos(pos);
		newT->SetVel(RandomizeDir(vel, 10));
		spawnQueue->Add(newT);
		remainingTime = cooldown;
	}
}


#endif