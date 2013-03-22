#include "Logs.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

char *ErrStr(int errorLevel)
{
	switch (errorLevel)
	{
	case MINOR_ERROR :	return "Minor error";
		break;
	case MEDIUM_ERROR :	return "Medium error";
		break;
	case MAJOR_ERROR :	return "Major error";
		break;
	case TESTING	:	return "TESTING only";
		break;
	}
	return "No Error";
}
int Log(char *msgString, int errorLevel,int whereTo)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

#ifdef CREATE_LOG
	{
		switch(whereTo)
		{
		case OUT_TO_FILE :
			{
				ofstream logFile;
				logFile.open ("log..txt",ios::app);
				logFile << "[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
					<< time.wMinute << ":" << time.wSecond << "] " << msgString << " " << ErrStr(errorLevel) << "\n";
				logFile.close();
			}
			break;
		case OUT_TO_SCR :
			{
				cout << "\n[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
					<< time.wMinute << ":" << time.wSecond << "] " << msgString << " " << ErrStr(errorLevel) << "\n";
			};
			break;
		}
		return 1;
	}
#else
	return 0;
#endif
}