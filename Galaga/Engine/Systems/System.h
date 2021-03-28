#ifndef ENGINE_SYSTEM
#define ENGINE_SYSTEM

#include "Engine/Entities/EntityRegistry.h"
#include "Engine/Engine.h"

class SystemBase
{
public:
	SystemBase();
	virtual ~SystemBase();

	bool IsActive() const;
	void Activate();
	void Deactivate();

	virtual unsigned short GetID() const = 0;
	virtual void Work(EntityRegistry& registry) = 0;

protected:
	bool isActive;

	unsigned short GetNextID();

private:
	static unsigned short nextID;
};

template <typename T>
class System : public SystemBase
{
public:
	System();
	~System();

	static unsigned short ID;
	unsigned short GetID() const override;
	virtual void Work(EntityRegistry& registry) = 0;
};

template <typename T> unsigned short System<T>::ID = 0;

template <typename T>
System<T>::System()
{
	ID = (ID == 0) ? SystemBase::GetNextID() : ID;
}

template <typename T>
System<T>::~System() {};

template <typename T>
unsigned short System<T>::GetID() const
{
	return System<T>::ID;
}

#endif
