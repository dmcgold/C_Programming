#include "Logs.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

char *ErrStr(int ErrorLevel)
{
	switch (ErrorLevel)
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
int Log(char *Str, int ErrorLevel,int Output)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

#ifdef CREATE_LOG
	{
		switch(Output)
		{
		case OUT_TO_FILE :
			{
				ofstream LogFile;
				LogFile.open ("log..txt",ios::app);
				LogFile << "[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
					<< time.wMinute << ":" << time.wSecond << "] " << Str << " " << ErrStr(ErrorLevel) << "\n";
				LogFile.close();
			}
			break;
		case OUT_TO_SCR :
			{
				cout << "\n[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
					<< time.wMinute << ":" << time.wSecond << "] " << Str << " " << ErrStr(ErrorLevel) << "\n";
			};
			break;
		}
		return 1;
	}
#else
	return 0;
#endif
}