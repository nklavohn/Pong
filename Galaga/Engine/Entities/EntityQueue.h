#ifndef ENGINE_ENTITYQUEUE
#define ENGINE_ENTITYQUEUE

#include <queue>
#include <memory>

template <class T>
class entity_queue
{
public:
	static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity");
	
	std::queue<std::shared_ptr<T>> Ts = std::queue<std::shared_ptr<T>>();

	void Add(std::shared_ptr<T> newT);
	std::shared_ptr<T> Pop();
	int Size() const;
	bool IsEmpty() const;
};

template <class T>
void entity_queue<T>::Add(std::shared_ptr<T> newT)
{
	Ts.push(newT);
}

template <class T>
std::shared_ptr<T> entity_queue<T>::Pop()
{
	std::shared_ptr<T> frontT = Ts.front();
	Ts.pop();
	return frontT;
}

template <class T>
int entity_queue<T>::Size() const
{
	return Ts.size();
}

template <class T>
bool entity_queue<T>::IsEmpty() const
{
	return Ts.empty();
}


#endif
