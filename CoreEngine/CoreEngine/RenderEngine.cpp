#include "RenderEngine.h"


CRenderEngine::CRenderEngine(CWindowManager* renderWindow)
{
		//Setting IDs and incrementing the renderer count
	//m_iRenderID = m_iRendererInstances;
	//m_iRendererInstances++;	
		//setting variables
	m_wmRenderWindow = renderWindow;
}

bool CRenderEngine::loadBackgroundFromBMP(string filepath)
{
	m_structBackground.m_SDLsSurface = SDL_LoadBMP(filepath.c_str());
	if (m_structBackground.m_SDLsSurface == NULL)
	{
		return true;
	}
	m_structBackground.m_SDLtTexture = SDL_CreateTextureFromSurface(m_wmRenderWindow->getSDLRenderer(), m_structBackground.m_SDLsSurface);
	SDL_FreeSurface(m_structBackground.m_SDLsSurface);
	if (m_structBackground.m_SDLtTexture == NULL)
	{
		return true;
	}
	return false;
}

void CRenderEngine::renderBackgound()
{
	//Clear muss evtl entfernt werden!!!!!
	SDL_RenderClear(m_wmRenderWindow->getSDLRenderer());
	//////////
	SDL_RenderCopy(m_wmRenderWindow->getSDLRenderer(), m_structBackground.m_SDLtTexture, NULL, NULL);
}

void CRenderEngine::drawAll(int startPosX, int startPosY)
{
	/*
	Beim rendern ausschnit übergabe. 
	Background größer als auflösung dann einfach verschieben
	Festgelegte Map Größe (ATT in struct)
	Map int array datei mit bildpunkten als wert für passierbar, bebaubar usw
	(auch att in struct)
	*/
	renderBackgound();
	SDL_RenderPresent(m_wmRenderWindow->getSDLRenderer());
}

void CRenderEngine::clearBackground()
{
	SDL_DestroyTexture(m_structBackground.m_SDLtTexture);
}

void CRenderEngine::clearAll()
{
	clearBackground();
	SDL_DestroyRenderer(m_wmRenderWindow->getSDLRenderer());
	SDL_DestroyWindow(m_wmRenderWindow->getSDLWindow());
	SDL_Quit();
}

CRenderEngine::~CRenderEngine()
{
}
