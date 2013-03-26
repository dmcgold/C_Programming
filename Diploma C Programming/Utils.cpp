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
	return newString;
}


char displayMenu(char *getMenuChoices[])
{
	int maxItems=atoi(getMenuChoices[0])+1;
	int maxLen=strlen(" Select option to run \n");

	// Get the max length of the menu strings

	for ( int a=0;a<maxItems;a++)
	{
		(( int ) strlen(getMenuChoices[a]) > maxLen) ? maxLen=strlen(getMenuChoices[a]) : maxLen=maxLen;
	}


	system("cls");

	// Drawing lines

	printf("%c",201);
	for ( int a=1;a<maxLen;a++)
		printf("%c",205);
	printf("%c\n",187);

	printf("%c Select option to run %c\n",186,186);
		printf("%c",199);
	for ( int b=1;b<maxLen;b++)
		printf("%c",196);
	printf("%c\n",182);
	
	// Display Menu

	for ( int menuCounter=1;menuCounter<maxItems;menuCounter++)
	{
		printf("%c %d) %s",186,menuCounter,getMenuChoices[menuCounter]);
		for( int b=1;b<( int )(maxLen-strlen(getMenuChoices[menuCounter])-4);b++)
			printf(" ");
		printf("%c\n",186);
	}

	// Drawing lines

	printf("%c",199);
	for( int b=1;b<maxLen;b++)
		printf("%c",196);
	printf("%c\n",182);
	printf("%c Q) to Quit           %c\n",186,186);
	printf("%c",200);
	for ( int a=1;a<maxLen;a++)
		printf("%c",205);
	printf("%c\n",188);

	// Get character and run
	return GetCh();
	
}
