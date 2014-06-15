// WindowManagerEngineKrams.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "SDL.h"
#include "stdafx.h"
#include "CoreDialog.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	cout << CCoreDialog::promt("Neuer Held", "Deine Mudda") << endl;
	system("pause");
	return 0;
}

