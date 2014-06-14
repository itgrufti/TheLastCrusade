#pragma once
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
using namespace std;
class CCoreDialog
{

public:
	CCoreDialog();
	static string promt(string windowCaption, string message);
	~CCoreDialog();
};

