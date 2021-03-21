#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL

#include "Entity.h"
#include <unordered_map>
#include <memory>

template <class T>
class entity_pool
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity");

	entity_pool();
	~entity_pool();

	void Update();
	void Render() const;
	void DebugPhysics() const;
	void Add(int key, std::shared_ptr<Entity> entity);
	std::shared_ptr<Entity> GetEntity(const int& id) const;
	int Size() const;



private:
	std::unordered_map<int, std::shared_ptr<T>> entities{};
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

template <class T>
int entity_pool<T>::Size() const
{
	return entities.size();
}

template <class T>
void entity_pool<T>::Add(int key, std::shared_ptr<Entity> entity)
{
	entities.emplace(key, std::dynamic_pointer_cast<T>(entity));
}

template <class T>
std::shared_ptr<Entity> entity_pool<T>::GetEntity(const int& id) const
{
	return std::dynamic_point_cast<Entity>(Ts.at(id));
}

#endif