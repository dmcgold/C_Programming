#include "Utils.h"
#include <Windows.h>
#include <string>

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

char GetCh(void)
{
	char Ch=' ';
	do
	{
		Ch=toupper(_getch());
	} while (Ch==' ');
	return Ch;
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

__int64 StartCounter(double *PCFreq,int Accuracy)
{
	LARGE_INTEGER li;
	if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

	
	switch (Accuracy)
	{
		case 0 : *PCFreq = double(li.QuadPart);break; // Seconds
		case 1 : *PCFreq = double(li.QuadPart)/1000.0;break; // Milliseconds
		case 2 : *PCFreq = double(li.QuadPart)/1000000.0;break; // Microseconds
		default : *PCFreq = double(li.QuadPart)/1000.0;break; // Milliseconds
	}

	QueryPerformanceCounter(&li);
	return (li.QuadPart);
}

double GetCounter(__int64 CounterStart,double PCFreq)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart-CounterStart)/PCFreq;
}

