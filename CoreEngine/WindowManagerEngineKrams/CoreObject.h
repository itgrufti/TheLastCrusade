#pragma once
#include "Position.h"
#include <string>
#include "SDL.h"
using namespace std;
class CCoreObject
{
private:
	//static int m_iIDCounter;
	int m_iID;
	string m_sName;
	bool m_bIsClicked;
	Position m_posObjectPos;
	Position m_posEndRenderPos;
	SDL_Texture* m_sdslTexture;
	void* m_vptrFunctionPressed;
public:
	CCoreObject(void* fnPtr, Position pos, Position endPos, SDL_Texture* texture, string name);
	CCoreObject::CCoreObject();
	void handleClick();
	void changeTexture(SDL_Texture* newTexture);
	~CCoreObject();
};

