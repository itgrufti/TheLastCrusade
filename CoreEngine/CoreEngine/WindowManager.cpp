#include "WindowManager.h"
#include "ErrorHandler.h"



//Public methods

bool CWindowManager::startUp()
{
	
	//Start SDL 
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		return true;
	}
	initVideo();
	return false;
}

bool CWindowManager::exit()
{
	//Quit SDL 
	SDL_Quit();
	return 0;
}



CWindowManager::CWindowManager(int vSizeX, int vSizeY, int colorDepht, string windowTitle)
{
	this->colorDepht = colorDepht;
	this->vSizeX = vSizeX;
	this->vSizeY = vSizeY;
	this->windowTitle = windowTitle;
}

bool CWindowManager::initVideo()
{
	m_SDLWmainWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, vSizeX, vSizeY,NULL);
	if (m_SDLWmainWindow == NULL)
	{
		return true;
	}
	m_SDLRmainRenderer = SDL_CreateRenderer(m_SDLWmainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_SDLRmainRenderer == NULL)
	{
		return true;
	}

}



SDL_Window* CWindowManager::getSDLWindow()
{
	return m_SDLWmainWindow;
}
SDL_Renderer* CWindowManager::getSDLRenderer()
{
	return m_SDLRmainRenderer;
}


CWindowManager::~CWindowManager()
{
}
