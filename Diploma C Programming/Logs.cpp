#include "Logs.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;




char *ErrStr(int ErrorLevel)
{
	switch (ErrorLevel)
	{
		case MinorError :	return "Minor error";
							break;
		case MediumError :	return "Medium error";
							break;
		case MajorError :	return "Major error";
							break;
		case Testing	:	return "Testing only";
							break;
	}
	return "No Error";

}
int Log(char *Str, int ErrorLevel,int Output)
{
	SYSTEMTIME time;
	GetLocalTime(&time); 

	#ifdef CreateLog
	{
		switch(Output)
		{
			case Out_to_File : 
			{
				ofstream LogFile;
				LogFile.open ("log..txt",ios::app);
				LogFile << "[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
						<< time.wMinute << ":" << time.wSecond << "] " << Str << " " << ErrStr(ErrorLevel) << "\n";
				LogFile.close();

			}
				break;
			case Out_to_Scr : 
			{
				cout << "[" <<time.wDay << "/" << time.wMonth << "/" << time.wYear << "][" << time.wHour << ":"
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