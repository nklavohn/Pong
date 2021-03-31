#ifndef ENGINE_CONSTANTEMITTER
#define ENGINE_CONSTANTEMITTER

#include "Emitter.h"
#include "Engine/Engine.h"

template <class T>
class ConstantEmitter : public Emitter<T>
{
public:
	ConstantEmitter(std::unique_ptr<T> _t, const float& _cooldown);
	ConstantEmitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ConstantEmitter();

	void Emit(const Vector2& pos, const Vector2& vel) override;
};

template <class T>
ConstantEmitter<T>::ConstantEmitter(std::unique_ptr<T> _t, const float& _cooldown) : Emitter<T>(std::move(_t), _cooldown)
{

}

template <class T>
ConstantEmitter<T>::ConstantEmitter(std::unique_ptr<T> _t, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue) 
	: Emitter<T>(std::move(_t), _cooldown, sQueue)
{
	
}

template <class T>
ConstantEmitter<T>::~ConstantEmitter()
{

}

template <class T>
void ConstantEmitter<T>::Emit(const Vector2& pos, const Vector2& vel)
{
	remainingTime -= Engine::GetDeltaTime();

	if (remainingTime < 0)
	{
		std::shared_ptr<T> newT = t->CloneEntity();
		newT->SetPos(pos);
		newT->SetVel(RandomizeDir(vel, 10));
		spawnQueue->Add(newT);
		remainingTime += cooldown;
	}
}

#endif
