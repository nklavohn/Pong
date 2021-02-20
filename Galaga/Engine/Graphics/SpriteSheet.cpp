#include "SpriteSheet.h"

SpriteSheet::SpriteSheet() : Sprite()
{
	Initialize(IVector2::ONE);
}

SpriteSheet::SpriteSheet(string imgPath, IVector2 _dim) : Sprite(imgPath)
{
	Initialize(_dim);
}

SpriteSheet::SpriteSheet(string imgPath, IVector2 _dim, Vector2 _pos) : Sprite(imgPath, _pos)
{
	Initialize(_dim);
}

SpriteSheet::SpriteSheet(string imgPath, IVector2 _dim, Vector2 _pos, float _scale) : Sprite(imgPath, _pos, _scale)
{
	Initialize(_dim);
}

SpriteSheet::SpriteSheet(int imgID, IVector2 _dim) : Sprite(imgID)
{
	Initialize(_dim);
}

SpriteSheet::SpriteSheet(int imgID, IVector2 _dim, Vector2 _pos) : Sprite(imgID, _pos)
{
	Initialize(_dim);
}

SpriteSheet::SpriteSheet(int imgID, IVector2 _dim, Vector2 _pos, float _scale) : Sprite(imgID, _pos, _scale)
{
	Initialize(_dim);
}

void SpriteSheet::Initialize(IVector2 _dim)
{
	dimPxl = _dim;
	dimPercent = Vector2((float)dimPxl.x / texture.GetWidth(), (float)dimPxl.y / texture.GetHeight());
}

void SpriteSheet::RenderSprite(IVector2 spriteCoord)
{
	RenderSpriteHelper(spriteCoord, pos);
}

void SpriteSheet::RenderSpriteRelativeTo(Vector2 _pos, IVector2 spriteCoord)
{
	RenderSpriteHelper(spriteCoord, pos + _pos);
}

void SpriteSheet::RenderSpriteHelper(IVector2 spriteCoord, Vector2 offset)
{
	// ------------ Setup -------------
	// because gl is a state machine, we do not know what state it may be when this code is run, so we need to do a few things first
	// enable the texture_2D
	glEnable(GL_TEXTURE_2D);

	// bind the texture's id to GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, texture.GetID());

	// set the type of interpolation/filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, interp);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, interp);

	// start fresh with the identity matrix (no transformations)
	glLoadIdentity();

	// first execute locations
	Vector2 center = Vector2((float)(dimPxl.x) / 2 * scale.x, (float)(dimPxl.y) / 2 * scale.y);
	glTranslatef(offset.x - center.x, offset.y - center.y, 0);

	// then execute rotations
	// rotates around the z axis (perpendicular to screen) only, because it is a 2D game
	glRotatef(rot, 0, 0, 1);

	// then execute scales
	glScalef(scale.x, scale.y, 1);


	// --------- Actual Rendering ----------
	// we don't know what the color is currently set to, so set it to white with full alpha
	glColor4f(1, 1, 1, 1);

	// begin rendering
	glBegin(GL_QUADS);

	// this takes the bottom left coordinate of the image, (0,0) and draws it at (xPos, yPos)
	// because we translated already above, xPos and yPos is now at (0, 0)
	Vector2 start = spriteCoord.ToVector() * dimPercent;

	glTexCoord2f(start.x, 0);											glVertex2f(0, 0);

	// around the image counter clockwise (this matters)
	glTexCoord2f(start.x + dimPercent.x, 0);							glVertex2f(dimPxl.x, 0);
	glTexCoord2f(start.x + dimPercent.x, start.y + dimPercent.y);		glVertex2f(dimPxl.x, dimPxl.y);
	glTexCoord2f(start.x, start.y + dimPercent.y);						glVertex2f(0, dimPxl.y);

	// ends the drawing. its a state machine, so you need to end what you are doing
	glEnd();
	glDisable(GL_TEXTURE_2D);
}