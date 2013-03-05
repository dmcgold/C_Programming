#include "Utils.h"

using namespace std;

void PressKey(char *Str)
{
	char Ch=(char) 254;
	cout << Str << endl << endl << "Press any key to cont";
	do
	{
		Ch=_getch();
	}
	while (Ch==254);
}

SYSTEMTIME GetTotalTime(SYSTEMTIME Start,SYSTEMTIME End)
{
	SYSTEMTIME TotalTime=End;

	if((End.wHour-Start.wHour)<0)
	{
		TotalTime.wDay++;
		TotalTime.wHour=((60-End.wHour) + (Start.wHour))-60;
	}
	else
	{
		TotalTime.wHour=(End.wHour) + (Start.wHour);
	}

	if((End.wMinute-Start.wMinute)<0)
	{
		TotalTime.wHour++;
		TotalTime.wMinute=((60-End.wMinute) + (Start.wMinute))-60;
	}
	else
	{
		TotalTime.wMinute=(End.wMinute-Start.wMinute);
	}

	if((End.wSecond-Start.wSecond)<0)
	{
		TotalTime.wMinute++;
		TotalTime.wSecond=((60-End.wSecond) + (Start.wSecond))-60;
	}
	else
	{
		TotalTime.wSecond=(End.wSecond-Start.wSecond);
	}

	if((End.wMilliseconds-Start.wMilliseconds)<0)
	{
		TotalTime.wSecond++;
		TotalTime.wMilliseconds=((60-End.wMilliseconds) + (Start.wMilliseconds))-1000;
	}
	else
	{
		TotalTime.wMilliseconds=(End.wMilliseconds-Start.wMilliseconds);
	}

	return TotalTime;
}