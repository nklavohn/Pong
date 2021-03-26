#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL

#include "Entity.h"
#include <unordered_map>
#include <memory>

template <class T>
class EntityPool
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity");

	std::unordered_map<int, std::shared_ptr<T>> entities{};

	EntityPool();
	~EntityPool();

	void Update();
	void Render() const;
	void DebugPhysics() const;
	void Add(int key, std::shared_ptr<Entity> entity);
	void Remove(int key);
	std::shared_ptr<Entity> GetEntity(const int& id) const;
	int Size() const;
};

template <class T>
EntityPool<T>::EntityPool()
{

}

template <class T>
EntityPool<T>::~EntityPool()
{

}

template <class T>
void EntityPool<T>::Update()
{
	for (auto& itr : entities)
	{
		itr.second->Update();
	}
}

template <class T>
void EntityPool<T>::Render() const
{
	for (auto& itr : entities)
	{
		itr.second->Render();
	}
}


template <class T>
void EntityPool<T>::DebugPhysics() const
{
	for (auto& itr : entities)
	{
		itr.second->DebugPhysics();
	}
}

template <class T>
int EntityPool<T>::Size() const
{
	return entities.size();
}

template <class T>
void EntityPool<T>::Add(int key, std::shared_ptr<Entity> entity)
{
	entities.emplace(key, std::dynamic_pointer_cast<T>(entity));
}

template <class T>
void EntityPool<T>::Remove(int key)
{
	entities.erase(key);
}

template <class T>
std::shared_ptr<Entity> EntityPool<T>::GetEntity(const int& id) const
{
	return std::dynamic_pointer_cast<Entity>(entities.at(id));
}

#endif