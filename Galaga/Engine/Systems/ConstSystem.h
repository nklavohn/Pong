#ifndef ENGINE_CONSTSYSTEM
#define ENGINE_CONSTSYSTEM

#include "Engine/Entities/EntityRegistry.h"
#include "Engine/Engine.h"

class ConstSystemBase
{
public:
	ConstSystemBase();
	virtual ~ConstSystemBase();

	bool IsActive() const;
	void Activate();
	void Deactivate();

	virtual unsigned short GetID() const = 0;
	virtual void Work(const EntityRegistry& registry) const = 0;

protected:
	bool isActive;

	unsigned short GetNextID();

private:
	static unsigned short nextID;
};

template <typename T>
class ConstSystem : public ConstSystemBase
{
public:
	ConstSystem();
	~ConstSystem();

	static unsigned short ID;
	unsigned short GetID() const override;
	virtual void Work(const EntityRegistry& registry) const = 0;
};

template <typename T> unsigned short ConstSystem<T>::ID = 0;

template <typename T>
ConstSystem<T>::ConstSystem()
{
	ID = (ID == 0) ? ConstSystemBase::GetNextID() : ID;
}

template <typename T>
ConstSystem<T>::~ConstSystem() {};

template <typename T>
unsigned short ConstSystem<T>::GetID() const
{
	return ConstSystem<T>::ID;
}

#endif