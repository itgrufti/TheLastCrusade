#pragma once
#include "CoreWindow.h"
#include "CoreObject.h"
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
	bool addObject(int windowID, int objectID);
	bool deleteWindow(int index);

	~CCoreEngine();
};

