// WindowManagerEngineKrams.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//
#include "SDL.h"
#include "stdafx.h"
#include "CoreDialog.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	cout << CCoreDialog::promt("test", "test") << endl;
	system("pasue");
	return 0;
}

