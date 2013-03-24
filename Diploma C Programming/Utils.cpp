#include "Utils.h"

using namespace std;

void PressKey(char *msgString)
{
	char getChar=(char) 254;
	cout << msgString << endl << endl << "Press any key to cont";
	do
	{
		getChar=_getch();
	}
	while (getChar==254);
}

char GetCh(void)
{
	char chosenChar=' ';
	do
	{
		chosenChar=toupper(_getch());
	} while (chosenChar==' ');
	return chosenChar;
}

SYSTEMTIME GetTotalTime(SYSTEMTIME startTime,SYSTEMTIME endTime)
{
	SYSTEMTIME totalTime=endTime;

	if ((endTime.wHour-startTime.wHour)<0)
	{
		totalTime.wDay++;
		totalTime.wHour=((60-endTime.wHour) + (startTime.wHour))-60;
	}
	else
	{
		totalTime.wHour=(endTime.wHour) + (startTime.wHour);
	}

	if ((endTime.wMinute-startTime.wMinute)<0)
	{
		totalTime.wHour++;
		totalTime.wMinute=((60-endTime.wMinute) + (startTime.wMinute))-60;
	}
	else
	{
		totalTime.wMinute=(endTime.wMinute-startTime.wMinute);
	}

	if ((endTime.wSecond-startTime.wSecond)<0)
	{
		totalTime.wMinute++;
		totalTime.wSecond=((60-endTime.wSecond) + (startTime.wSecond))-60;
	}
	else
	{
		totalTime.wSecond=(endTime.wSecond-startTime.wSecond);
	}

	if ((endTime.wMilliseconds-startTime.wMilliseconds)<0)
	{
		totalTime.wSecond++;
		totalTime.wMilliseconds=((60-endTime.wMilliseconds) + (startTime.wMilliseconds))-1000;
	}
	else
	{
		totalTime.wMilliseconds=(endTime.wMilliseconds-startTime.wMilliseconds);
	}

	return totalTime;
}

__int64 StartCounter(double *pcFreq,int timeAccuracy)
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	switch (timeAccuracy)
	{
		case SECONDS		:	*pcFreq = double(li.QuadPart);
								break;
		case MILLISECONDS	:	*pcFreq = double(li.QuadPart)/1000.0;
								break;
		case MICROSECONDS	:	*pcFreq = double(li.QuadPart)/1000000.0;
								break;
		default :				*pcFreq = double(li.QuadPart)/1000.0;
								break; // Milliseconds
	}

	QueryPerformanceCounter(&li);
	return (li.QuadPart);
}

double GetCounter(__int64 counterStart,double pcFreq)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart-counterStart)/pcFreq;
}

char *RandomString(int strSize)
{
	int no=1;
	char newString[]="1234567890";	

	for (int b=0;b<strSize;b++){
		while ((no<65) || (no>90) && ((no<97) || (no>122)))
			no=((rand() % (122+1-65))+65);
		newString[b]=no;
		no=0;
	}
	return (newString);
}

char displayMenu(char *getMenuChoices[])
{
	int maxItems=atoi(getMenuChoices[0])+1;

	system("cls");

	printf("          Select option to run\n");
	printf("         ______________________\n");
	
	for (int menuCounter=1;menuCounter<maxItems;menuCounter++)
		printf("          %d) %s\n",menuCounter,getMenuChoices[menuCounter]);

	printf("         ______________________\n");
	printf("          Q) to Quit\n");
	return(GetCh());
}
