#pragma once
#include"CoreObject.h"
#include "ObjectTemplate.h"
#include <string>
#include <vector>
using namespace std;
class CCoreObjectHelper
{
private:
	vector<ObjectTemplate*> m_vObjectTemplates;	//ObjectTemplates where loaded from the file into here
	vector<CCoreObject> m_vObjectList;			//All generated object are sored here
public:
	CCoreObjectHelper();
	bool loadFromFile();						//Loads templates from file
	int createObject(string name);				//Creates an unique object, returns ID if no template is found return 9999
	bool deleteObject(int index);
	~CCoreObjectHelper();
};

