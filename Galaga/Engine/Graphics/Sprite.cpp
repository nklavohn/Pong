#include "Sprite.h"


Sprite::Sprite()
{
	Initialize(-1, Vector2::ZERO, Vector2::ONE, 0);
}

Sprite::Sprite(const std::string& imgPath)
{
	Initialize(imgPath, Vector2::ZERO, Vector2::ONE, 0);
}

Sprite::Sprite(const int& imgID)
{
	Initialize(imgID, Vector2::ZERO, Vector2::ONE, 0);
}

Sprite::Sprite(const std::string& imgPath, const Vector2& _pos)
{
	Initialize(imgPath, _pos, Vector2::ONE, 0);
}

Sprite::Sprite(const int& imgID, const Vector2& _pos)
{
	Initialize(imgID, _pos, Vector2::ONE, 0);
}

Sprite::Sprite(const std::string& imgPath, const Vector2& _pos, const float& _scale)
{
	Initialize(imgPath, _pos, Vector2(_scale), 0);
}

Sprite::Sprite(const int& imgID, const Vector2& _pos, const float& _scale)
{
	Initialize(imgID, _pos, Vector2(_scale), 0);
}

void Sprite::Initialize(const std::string& imgPath, const Vector2& _pos, const Vector2& _scale, const float& _rot)
{
	texture = Texture(imgPath);
	pos = _pos;
	scale = _scale;
	rot = _rot;
	rotCenter = Vector2(texture.GetWidth(), texture.GetHeight()) / 2;
	rotCenterAdj = rotCenter * scale;
}

void Sprite::Initialize(const int& imgID, const Vector2& _pos, const Vector2& _scale, const float& _rot)
{
	texture = Texture(imgID);
	pos = _pos;
	scale = _scale;
	rot = _rot;
	rotCenter = Vector2(texture.GetWidth(), texture.GetHeight()) / 2;
	rotCenterAdj = rotCenter * scale;
}

Sprite::~Sprite()
{

}

void Sprite::Render() const
{
	RenderHelper(pos, rot);
}

void Sprite::RenderRelativeTo(const Vector2& _pos) const
{
	RenderHelper(pos + _pos, rot);
}

void Sprite::RenderRelativeTo(const Vector2& _pos, const float& _rot) const
{
	RenderHelper(pos + _pos, rot + _rot);
}

void Sprite::RenderHelper(const Vector2& posOffset, const float& rotOffset) const
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
	glTranslatef(posOffset.x, posOffset.y, 0);

	// then execute rotations
	// rotates around the z axis (perpendicular to screen) only, because it is a 2D game
	glRotatef(rotOffset, 0, 0, 1);

	glTranslatef(-rotCenter.x, -rotCenterAdj.y, 0);

	// then execute scales
	glScalef(scale.x, scale.y, 1);


	// --------- Actual Rendering ----------
	// we don't know what the color is currently set to, so set it to white with full alpha
	glColor4f(1, 1, 1, 1);

	// begin rendering
	glBegin(GL_QUADS);

	// this takes the bottom left coordinate of the image, (0,0) and draws it at (xPos, yPos)
	// because we translated already above, xPos and yPos is now at (0, 0)
	glTexCoord2f(0, 0);		glVertex2f(0, 0);

	// around the image counter clockwise (this matters)
	glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth(), texture.GetHeight());
	glTexCoord2f(0, 1);		glVertex2f(0, texture.GetHeight());

	// ends the drawing. its a state machine, so you need to end what you are doing
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Sprite::SetPos(const float& x, const float& y)
{
	pos.x = x;
	pos.y = y;
}

void Sprite::SetPos(const Vector2& v)
{
	pos.x = v.x;
	pos.y = v.y;
}

void Sprite::SetRot(const float& _rot)
{
	rot = _rot;
}

void Sprite::AddRot(const float& _rot)
{
	rot += _rot;
}

void Sprite::SetScale(const float& xy)
{
	scale.x = xy;
	scale.y = xy;
	rotCenterAdj = rotCenter * scale;
}

void Sprite::SetScale(const float& x, const float& y)
{
	scale.x = x;
	scale.y = y;
	rotCenterAdj = rotCenter * scale;
}

void Sprite::SetScale(const Vector2& v)
{
	scale.x = v.x;
	scale.y = v.y;
	rotCenterAdj = rotCenter * scale;
}

void Sprite::SetRotCenter(const Vector2& _rotCenter)
{
	rotCenter = _rotCenter;
	rotCenterAdj = rotCenter * scale;
}

void Sprite::SetInterpolationFunction(const int& _interp)
{
	interp = _interp;
}

float Sprite::GetHeight(bool scaled) const
{
	if (scaled) return texture.GetHeight() * scale.y;
	return texture.GetHeight();
}

float Sprite::GetWidth(bool scaled) const
{
	if (scaled) return texture.GetWidth() * scale.x;
	return texture.GetWidth();
}

int Sprite::GetTextureID() const 
{
	return texture.GetID();
}