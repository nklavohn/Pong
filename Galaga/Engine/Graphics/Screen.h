#ifndef ENGINE_SCREEN
#define ENGINE_SCREEN

#include "GLFW/glfw3.h"
#include "Color.h"
#include "Engine/Math/IVector2.h"

class Screen {

public:
	virtual void Update() = 0;
	virtual void Render() const = 0;
	virtual Screen* Clone() const = 0;

	int GetWidth() const;
	int GetHeight() const;
	IVector2 GetDim() const;
	void SetDim(const IVector2& _dim);

	Screen();
	Screen(const IVector2& _dim);
	virtual ~Screen();

protected:
	IVector2 dim;

	Color color;

	void BeginRender() const;
	void EndRender() const;
};

#endif