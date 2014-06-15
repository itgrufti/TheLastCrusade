#pragma once
#include "CoreEngine.h"
#include <iostream>


CCoreEngine::CCoreEngine()
{
	m_irrAudioEngine = createIrrKlangDevice();
	if (!m_irrAudioEngine)
	{
		cout << "Could not load audio engine...Aborting!";
		system("pause");
		exit(1);
	}
}

int CCoreEngine::createMenueWindow(string caption, string backgroundGfx)
{

}
int CCoreEngine::createRenderWindow(string caption, string backgroundGfx, string overlayGfx)
{

}
bool CCoreEngine::addObject(int windowID, int objectID)
{

}
bool CCoreEngine::deleteWindow(int index)
{

}
CCoreEngine::~CCoreEngine()
{
}
