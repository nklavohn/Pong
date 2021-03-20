#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL
#include <vector>
#include "Entity.h"
#include <set>
#include <queue>
#include <memory>

template <class T>
class entity_pool
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity");
	std::vector<std::shared_ptr<T>> entities{};

	entity_pool();
	~entity_pool();

	void Update();
	void Render() const;
	void DebugPhysics() const;

private:
	
};

template <class T>
entity_pool<T>::entity_pool()
{

}

template <class T>
entity_pool<T>::~entity_pool()
{

}

template <class T>
void entity_pool<T>::Update()
{
	for (auto& itr : entities)
	{
		itr->Update();
	}
}

template <class T>
void entity_pool<T>::Render() const
{
	for (auto& itr : entities)
	{
		itr->Render();
	}
}


template <class T>
void entity_pool<T>::DebugPhysics() const
{
	for (auto& itr : entities)
	{
		itr->DebugPhysics();
	}
}

#endif