#include "CoreObject.h"




CCoreObject::CCoreObject(void* fnPtr, Position pos, Position endPos, SDL_Texture* texture, string name)
{
	m_bIsClicked = false;
	m_iID = 0;
	m_posObjectPos = pos;
	m_posEndRenderPos = endPos;
	m_sdslTexture = texture;
	m_sName = name;
}
CCoreObject::CCoreObject()
{

}
void CCoreObject::handleClick()
{

}
void CCoreObject::changeTexture(SDL_Texture* newTexture)
{
//	delete m_sdslTexture;	//Prevent memory leaks
	m_sdslTexture = newTexture;
}
CCoreObject::~CCoreObject()
{
}
