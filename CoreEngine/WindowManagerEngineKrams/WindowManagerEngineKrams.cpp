// WindowManagerEngineKrams.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "SDL.h"
#include "stdafx.h"
#include "CoreDialog.h"
#include "CoreEngine.h"
#include "CoreObjectHelper.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	string userInput = CCoreDialog::promt("MP3 Player", "Welche OGG?");
	CCoreEngine* myEngine = new CCoreEngine();
	CCoreObjectHelper* myObjectHelper = new CCoreObjectHelper();
	myEngine->playSound(userInput);
	system("pause");
	return 0;
}

