#include "CoreObject.h"
CCoreObject::CCoreObject(SDL_Rect position, SDL_Texture* normalTexture, SDL_Texture* hoverTexture, string objectType)
{

}
CCoreObject::CCoreObject()
{

}
void CCoreObject::changeTexture(SDL_Texture* newTexture)
{

}
string CCoreObject::getType()
{
	return m_sObjectType;
}
int CCoreObject::getID()
{
	return m_iID;
}
CCoreObject::~CCoreObject()
{

}