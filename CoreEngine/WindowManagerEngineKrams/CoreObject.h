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
	SDL_Texture* m_sdlTexture;
	SDL_Texture* m_sdlHoverTexture;
	SDL_Texture* m_sdlactualTexture;
	string m_sObjectType;
private:
	//static int m_iIDCounter;

public:
	CCoreObject(SDL_Rect position, SDL_Texture* normalTexture, SDL_Texture* hoverTexture, string objectType);
	CCoreObject();
	void changeTexture(SDL_Texture* newTexture);
	void setPosition(SDL_Rect newPosition);
	SDL_Rect getPosition();
	string getType();
	int getID();
	SDL_Texture* getTexture();
	SDL_Texture* getHoverTexture();
	~CCoreObject();
};

