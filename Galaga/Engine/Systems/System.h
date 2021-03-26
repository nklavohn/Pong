#ifndef ENGINE_SYSTEM
#define ENGINE_SYSTEM

#include "Engine/Entities/EntityRegistry.h"
#include "Engine/Engine.h"

class System
{
public:
	System();
	virtual ~System();

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
class SystemID : public System
{
public:
	SystemID();
	~SystemID();

	static unsigned short ID;
	unsigned short GetID() const override;
	virtual void Work(EntityRegistry& registry) = 0;
};

template <typename T> unsigned short SystemID<T>::ID = 0;

template <typename T>
SystemID<T>::SystemID()
{
	ID = (ID == 0) ? System::GetNextID() : ID;
}

template <typename T>
SystemID<T>::~SystemID() {};

template <typename T>
unsigned short SystemID<T>::GetID() const
{
	return SystemID<T>::ID;
}

#endif
