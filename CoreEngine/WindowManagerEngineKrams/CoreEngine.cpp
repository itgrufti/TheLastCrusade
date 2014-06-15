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
	return 0;
}
int CCoreEngine::createRenderWindow(string caption, string backgroundGfx, string overlayGfx)
{
	return 0;
}
bool CCoreEngine::addObject(int windowID, int objectID)
{
	return 0;
}
bool CCoreEngine::deleteWindow(int index)
{
	return 0;
}
void CCoreEngine::playSound(string fileName)
{
	m_irrAudioEngine->play2D(fileName.c_str());
}
CCoreEngine::~CCoreEngine()
{
}
