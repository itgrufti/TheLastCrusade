#pragma once
#include "SDl.h"
#include <string>

using namespace std;

class CWindowManager
{
private:
	//VARIABLES
	SDL_Window*		m_SDLWmainWindow;
	SDL_Renderer*	m_SDLRmainRenderer;
	int				vSizeX; 
	int				vSizeY;
	int				colorDepht;
	string			windowTitle;
	//METHODS
	bool			initVideo();

public:
	//METHODS
	bool			startUp();
					CWindowManager(int vSizeX, int vSizeY, int colorDepht, string windowTitle);
	bool			exit();
	SDL_Window*		getSDLWindow();
	SDL_Renderer*	getSDLRenderer();
					~CWindowManager();
};

