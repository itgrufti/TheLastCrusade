#pragma once
#include "CoreWindow.h"
#include "CoreObject.h"
#include <SDL.h>
#include "SDL_ttf.h"
#include <SDL_image.h>
#include <irrKlang.h>
#include <vector>
#include <string>
using namespace std;
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

class CCoreEngine
{
private:
	ISoundEngine* m_irrAudioEngine;
	vector<CCoreWindow> m_vWindowList;
public:
	CCoreEngine();
	int createMenueWindow(string caption, string backgroundGfx);
	int createRenderWindow(string caption, string backgroundGfx, string overlayGfx);
	bool addObject(int windowID, int objectID);
	void playSound(string fileName);
	bool deleteWindow(int index);

	~CCoreEngine();
};

