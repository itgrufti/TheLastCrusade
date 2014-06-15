#pragma once
#include "CoreObjectHelper.h"
#include <fstream>
#define SEMICOLONS_PER_ROW 3

CCoreObjectHelper::CCoreObjectHelper()
{
}

bool CCoreObjectHelper::loadFromFile()
{
	ifstream file;
	file.open("object.cof", ios::in);
	string line;
	ObjectTemplate* workTemplate;
	string tmp[4];
	int pos;
	while (file.good())
	{
		file >> line;
		workTemplate = new ObjectTemplate;
		int i;
		for (i = 0; i < SEMICOLONS_PER_ROW; i++)
		{
			pos = line.find_last_of(';');
			tmp[i] = line.substr(pos + 1, 50);
			line = line.substr(0, pos);
		}
		tmp[i] = line;
		workTemplate->hoverGgfx = tmp[2];
		workTemplate->normalGfx = tmp[1];
		workTemplate->name = tmp[0];
		workTemplate->objectType = tmp[3];
		m_vObjectTemplates.push_back(workTemplate);
	}
}
int CCoreObjectHelper::createObject(string name)
{
	for (int i = 0; i < m_vObjectTemplates.size(); i++)
	{
		if (m_vObjectTemplates.at(i)->name == name)
		{
			{
				if (m_vObjectTemplates.at(i)->objectType == "button")
				{

				}
				if (m_vObjectTemplates.at(i)->objectType == "building")
				{

				}
				if (m_vObjectTemplates.at(i)->objectType == "entity")
				{

				}
				//Build Object here and return ID
			}
		}
	}
	//No template found, returning error
	return 9999;
}
CCoreObjectHelper::~CCoreObjectHelper()
{
}
