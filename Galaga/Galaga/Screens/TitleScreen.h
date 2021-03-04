#ifndef GALAGA_TITLESCREEN
#define GALAGA_TITLESCREEN

#include "Engine/Graphics/Sprite.h"
#include "Engine/Graphics/Screen.h"

class TitleScreen: public Screen {

public:
	void Update() override;
	void Render() const override;
	Screen* Clone() const override;

	TitleScreen(const IVector2& _dim);
	~TitleScreen();

private:
	Sprite title = Sprite("Galaga/Assets/title.png");

};

#endif
