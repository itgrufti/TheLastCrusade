// CoreEngine.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "WindowManager.h"
#include "RenderEngine.h"

int main( int argc, char* args[] ) 
{ 
	CWindowManager* managerHandle = new CWindowManager(1920, 1080, 24, "CoreEngine Test");
	managerHandle->startUp();
	CRenderEngine*  renderHandle = new CRenderEngine(managerHandle);
	renderHandle->loadBackgroundFromBMP("Guild-Wars-2-Map.bmp");
	renderHandle->drawAll(NULL,NULL);
	SDL_Delay(50000);
	
	return 0; 
}

