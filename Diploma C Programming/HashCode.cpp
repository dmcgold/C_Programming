#include "HashCode.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h> 
#include "Utils.h"


using namespace std;

long HashCode(string Str)
{
	long Hash = 0;
	int Length=Str.length();	

	if (!Str.empty()) 
	{        
		for (int A = 0; A < Length; A++) 
		{
			Hash = 31*Hash + (int) Str[A] + ((int) Str[A] >> 4);
		}
	}
	return Hash;
}



void HashMaps(void)
{
	map<string, int> m;
	struct { // Structure used to compare search speeds with Map
			 char Str[11];
			 int  Val;
			} TestArray[60000];
	int ArraySize = 60000;
	SYSTEMTIME  STime,ETime,TotalTime;
	
	char Str[11];
	char *S="**********";
	long SearchTimes[2];

	srand (time(NULL));
	strcpy(Str,S);
	
	for(int A=0;A<ArraySize;A++) // Fill array and map with random 6 letter words
	{
		for(int B=0;B<10;B++) // Create a random string
		{
			Str[B]=GetRandomChar(); // Letters from A to z
		}
		strcpy(TestArray[A].Str,Str);
		TestArray[A].Val=A;
		m[Str]=A;
	}
	strcpy(Str,TestArray[ArraySize/2].Str);   // Use whatever at the halfway element for our search
	int A=0;
	GetSystemTime(&STime);
	
	while(strcmp(TestArray[A].Str,Str) != 0)
	{
		A++;
	}
	
	GetSystemTime(&ETime);
	TotalTime=GetTotalTime(STime,ETime);
	
	cout << endl << "Search time (MM:SS:Milliseconds) " << (int) TotalTime.wMinute << ":"\
			<< (int) TotalTime.wSecond << ":" << (long) TotalTime.wMilliseconds << endl;
	
	SearchTimes[0]=(long) TotalTime.wMilliseconds;

	if(A<=ArraySize)
	{
		cout << "Found String" << endl;
		cout << "Key         " << "Value" << endl;
		cout << TestArray[A].Str << "  " << TestArray[A].Val << endl;
	}
	else
		cout << "String not found" << endl;
	GetSystemTime(&STime);
	
	if (m.find(Str) != m.end())
	{
		GetSystemTime(&ETime);
		TotalTime=GetTotalTime(STime,ETime);
		
		cout << endl << "Key found " << endl;
		cout << "Key         " << "Value" << endl;
		cout << Str << "  at " << m[Str] << endl;
		cout << endl << "Search time (MM:SS:Milliseconds) " << (int) TotalTime.wMinute << ":"\
			<< (int) TotalTime.wSecond << ":" << (long) TotalTime.wMilliseconds << endl;
		SearchTimes[1]=(long) TotalTime.wMilliseconds;
		cout << "Time to search Array " << SearchTimes[0] << "ms Time to search Map " << SearchTimes[1] << "ms" << endl;
		if(SearchTimes[0] < SearchTimes[1])
			cout << "The Array search was faster" << endl;
		else
			cout << "The Map search was faster" << endl;
	}
}
