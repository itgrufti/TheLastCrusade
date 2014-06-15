#pragma once
#include"CoreObject.h"
#include <string>
using namespace std;
class CCoreObjectHelper
{
public:
	CCoreObjectHelper();
	bool loadFromFile();	//Loads templates from file
	int createObject(string name);	//Creates an unique object, returns ID
	~CCoreObjectHelper();
};

