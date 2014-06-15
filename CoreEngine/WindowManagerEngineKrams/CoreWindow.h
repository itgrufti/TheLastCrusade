#pragma once
#include <string>
using namespace std;
class CCoreWindow
{
protected:
	string m_sWindowType;
public:
	CCoreWindow();
	virtual string getWindowType();
	~CCoreWindow();
};

