#pragma once
#include "WindowManager.h"
#include "SBackground.h"
class CRenderEngine
{
private:
	//static int		m_iRendererInstances;	//Must be set to zero before creating instances 
	CWindowManager*	m_wmRenderWindow;
	int				m_iRenderID;
	SBackground		m_structBackground;
	//methods
	void renderBackgound();
public:
	CRenderEngine(CWindowManager* renderWindow);
	bool loadBackgroundFromBMP(string filepath);
	void drawAll(int startPosX, int startPosY);
	void clearBackground();
	void clearAll();
	~CRenderEngine();
};

