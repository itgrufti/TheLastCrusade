#include "ErrorHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

CErrorHandler::CErrorHandler()
{
}

/*
void CErrorHandler::errorToFile(string errorMessage, int errorNumber, string filePath)
{
	ofstream errFile;
	errFile.open(filePath, ios::out);
	errFile << "Error: " << errorNumber << " ( " << errorMessage << " )" << endl;
	errFile.close();
}
*/
CErrorHandler::~CErrorHandler()
{
}
