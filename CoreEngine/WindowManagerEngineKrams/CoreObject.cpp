#include "CoreObject.h"
CCoreObject::CCoreObject(SDL_Rect position, SDL_Texture* normalTexture, SDL_Texture* hoverTexture, string objectType)
{
	m_sdlHoverTexture = hoverTexture;
	m_sdlTexture = normalTexture;
	m_sdlactualTexture = normalTexture;
	m_sdlObjectPos = position;
	m_sObjectType = objectType;
}
CCoreObject::CCoreObject()
{

}
void CCoreObject::changeTexture(SDL_Texture* newTexture)
{
	m_sdlactualTexture = newTexture;
}
void CCoreObject::setPosition(SDL_Rect newPosition)
{
	m_sdlObjectPos = newPosition;
}
string CCoreObject::getType()
{
	return m_sObjectType;
}
int CCoreObject::getID()
{
	return m_iID;
}
SDL_Texture* CCoreObject::getTexture()
{
	return m_sdlTexture;
}
SDL_Texture* CCoreObject::getHoverTexture()
{
	return m_sdlHoverTexture;
}
SDL_Rect CCoreObject::getPosition()
{
	return m_sdlObjectPos;
}
CCoreObject::~CCoreObject()
{

}