#pragma once
#include "Position.h"
#include <string>
#include "SDL.h"
using namespace std;
class CCoreObject
{
protected:
	int m_iID;
	SDL_Rect m_sdlObjectPos;
	SDL_Texture* m_sdslTexture;
	SDL_Texture* m_sdlHoverTexture;
	string m_sObjectType;
private:
	//static int m_iIDCounter;

public:
	CCoreObject(SDL_Rect position, SDL_Texture* normalTexture, SDL_Texture* hoverTexture, string objectType);
	CCoreObject();
	void changeTexture(SDL_Texture* newTexture);
	string getType();
	~CCoreObject();
};

