#pragma once
#include "CoreObject.h"
#include <string>
#include <irrKlang.h>
#include <SDL.h>
#include "SDL_ttf.h"
#include <SDL_image.h>
#include <vector>
#include <boost/thread.hpp>
using namespace std;
using namespace irrklang;
class CCoreWindow
{
protected:
	ISoundEngine* m_irrAudioEngine;
	vector<CCoreObject*> m_vMainContentObjects;
	vector<CCoreObject*> m_vOverlayObjects;
	SDL_Window* m_sdlWindowHandler;
	SDL_Event m_sdlEvent;
	SDL_Renderer* m_sdlMainRenderer;
	TTF_Font* m_sdlMainFont;
	boost::thread* m_booRenderThread;
	boost::thread* m_booInteractionthread;

	int m_iLastClickedObjectID;
	int m_iLastClickedButton;

	void handleHoverClick();
	void render();
	void renderOverlay();
	void renderMainContent();
public:
	CCoreWindow(int siseX, int sizeY, ISoundEngine* audioEngine, string title);
	int getLastClickedObject();
	int getLastClickedButton();
	~CCoreWindow();
};

