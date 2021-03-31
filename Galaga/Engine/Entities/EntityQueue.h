#ifndef ENGINE_ENTITYQUEUE
#define ENGINE_ENTITYQUEUE

#include <queue>
#include <memory>

template <typename T>
class EntityQueue
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity... EntityQueue");
	
	std::queue<std::shared_ptr<T>> entities = std::queue<std::shared_ptr<T>>();

	void Add(std::shared_ptr<T> newT);
	std::shared_ptr<T> Pop();
	int Size() const;
	bool IsEmpty() const;
};

template <class T>
void EntityQueue<T>::Add(std::shared_ptr<T> newT)
{
	entities.push(newT);
}

template <class T>
std::shared_ptr<T> EntityQueue<T>::Pop()
{
	std::shared_ptr<T> frontT = entities.front();
	entities.pop();
	return frontT;
}

template <class T>
int EntityQueue<T>::Size() const
{
	return entities.size();
}

template <class T>
bool EntityQueue<T>::IsEmpty() const
{
	return entities.empty();
}


#endif
