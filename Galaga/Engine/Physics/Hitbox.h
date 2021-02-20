#ifndef ENGINE_HITBOX
#define ENGINE_HITBOX

#include "Engine/Math/Vector.h"
#include "Engine/Math/Vector4.h"

class Hitbox
{
public:
	

	void setCenter(Vector _center);
	void addToCenter(Vector delta);

private:
	Vector4 box;
	Vector center;
};

#endif