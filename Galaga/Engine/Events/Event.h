#ifndef ENGINE_EVENT
#define ENGINE_ENENT

class Event
{
public:
	Event();
	~Event();

	int GetNextID();

	const int id;

private:
	static int nextID;
};

#endif