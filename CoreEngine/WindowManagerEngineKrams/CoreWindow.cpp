#include "CoreWindow.h"


CCoreWindow::CCoreWindow(int sizeX, int sizeY, ISoundEngine* audioEngine, string title)
{
	m_sdlWindowHandler = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeX, sizeY, NULL);
	if (m_sdlWindowHandler == NULL)
	{
		system("pause");
		exit(1);
	}
	m_sdlMainRenderer = SDL_CreateRenderer(m_sdlWindowHandler, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_sdlMainRenderer == NULL)
	{
		system("pause");
		exit(1);
	}
	//************IMPROVEMENTS**************//
	// Read the font name from file,		//
	// Prompt error with prompt				//
	//**************************************//
	m_sdlMainFont = TTF_OpenFont("arial.ttf", 50);
	m_irrAudioEngine = audioEngine;
	m_iLastClickedObjectID = 0;
	m_booRenderThread = new boost::thread(boost::bind(&CCoreWindow::render, this));
	m_booInteractionthread = new boost::thread(boost::bind(&CCoreWindow::handleHoverClick, this));
}

int CCoreWindow::getLastClickedObject()
{
	return m_iLastClickedObjectID;
}



void CCoreWindow::renderOverlay()
{

}
void CCoreWindow::renderMainContent()
{

}




int CCoreWindow::getLastClickedButton()
{
	return m_iLastClickedButton;
}

void CCoreWindow::handleHoverClick()
{
	// Changing by hover the actualTexture to the hover texture
	int mouseX = 0;
	int mouseY = 0;
	SDL_Rect workRect;
	int xMax=0, yMax=0, xStart=0, yStart=0;
	while (true)
	{
		while (SDL_PollEvent(&m_sdlEvent) != 0)
		{
			if (m_sdlEvent.type == SDL_MOUSEMOTION)
			{
				mouseX = m_sdlEvent.motion.x;
				mouseY = m_sdlEvent.motion.y;
				for (int i = 0; i < m_vMainContentObjects.size(); i++)
				{
					workRect = m_vMainContentObjects.at(i)->getPosition();
					xStart = workRect.x;
					yStart = workRect.y;
					xMax = workRect.w + xStart;
					yMax = workRect.h + yStart;
					//Mouse is over the coordinates
					if (mouseX >= xStart && mouseX <= xMax && mouseY >= yStart && mouseY <= yMax)
					{
						m_vMainContentObjects.at(i)->changeTexture(m_vMainContentObjects.at(i)->getHoverTexture());
					}
					else
					{
						if (m_vMainContentObjects.at(i)->getHoverTexture() == m_vMainContentObjects.at(i)->getActualTexture())
						{
							m_vMainContentObjects.at(i)->changeTexture(m_vMainContentObjects.at(i)->getTexture());
						}
					}
				}
				for (int i = 0; i < m_vOverlayObjects.size(); i++)
				{
					workRect = m_vMainContentObjects.at(i)->getPosition();
					xStart = workRect.x;
					yStart = workRect.y;
					xMax = workRect.w + xStart;
					yMax = workRect.h + yStart;
					//Mouse is over the coordinates
					if (mouseX >= xStart && mouseX <= xMax && mouseY >= yStart && mouseY <= yMax)
					{
						m_vMainContentObjects.at(i)->changeTexture(m_vMainContentObjects.at(i)->getHoverTexture());
					}
					else
					{
						if (m_vMainContentObjects.at(i)->getHoverTexture() == m_vMainContentObjects.at(i)->getActualTexture())
						{
							m_vMainContentObjects.at(i)->changeTexture(m_vMainContentObjects.at(i)->getTexture());
						}
					}
				}
			}

			if (m_sdlEvent.type == SDL_MOUSEBUTTONDOWN)
			{
				int x = m_sdlEvent.button.x;
				int y = m_sdlEvent.button.y;
				
				for (int i = 0; i < m_vMainContentObjects.size(); i++)
				{
					workRect = m_vMainContentObjects.at(i)->getPosition();
					xStart = workRect.x;
					yStart = workRect.y;
					xMax = workRect.w + xStart;
					yMax = workRect.h + yStart;
					//Mouse is over the coordinates
					if (x >= xStart && x <= xMax && y >= yStart && y <= yMax)
					{
						m_iLastClickedObjectID = m_vMainContentObjects.at(i)->getID();
					}
				}
				for (int i = 0; i < m_vOverlayObjects.size(); i++)
				{
					workRect = m_vMainContentObjects.at(i)->getPosition();
					xStart = workRect.x;
					yStart = workRect.y;
					xMax = workRect.w + xStart;
					yMax = workRect.h + yStart;
					//Mouse is over the coordinates
					if (x >= xStart && x <= xMax && y >= yStart && y <= yMax)
					{
						m_iLastClickedObjectID = m_vMainContentObjects.at(i)->getID();
					}
				}
			}
		}
	}
}
void CCoreWindow::render()
{
	//Hier dann der Sleep wegen FPS begrenzung
	while (true)
	{
		renderMainContent();
		renderOverlay();
	}
}

CCoreWindow::~CCoreWindow()
{
}
