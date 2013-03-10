#include "HashCode.h"

long HashCode(string Str) // Simple but works
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
	return abs(Hash);
}

BOOLEAN BinarySearch(TA_Struct Search[],string SearchItem)
{
	int First = 0;
	int Last = ARRAY_SIZE - 1;
	int Middle = (First+Last)/2;
 
	while(First <= Last)
   {
	   if (Search[Middle].Str.compare(SearchItem) < 0)
		 First = Middle + 1;    
	  else if (Search[Middle].Str.compare(SearchItem)) 
	  {
		 break;
	  }
	  else
		 Last = Middle - 1;
 
	  Middle = (First+Last)/2;
   }
   if (First > Last)
	return false;
   else
	   return true;
}

void PrintMSG(string MSG,double SearchTime)
{
	cout << MSG << SearchTime << "ms" << endl << endl;
}

void InsertData(TA_Struct Data[],int Size,map<string,int> Sm)
{
	char S[]="1234567890";
	int No=1;
	
	srand (time(NULL));

	for(int A=0;A<Size;A++) // Fill array and map with random 6 letter words
	{
		for(int B=0;B<10;B++){	
				while((No<65) || (No>90) && ((No<97) || (No>122)))
					No=((rand() % (122+1-65))+65);
				S[B]=No;
				No=1;
			}
		Data[A].Str=S;
		Data[A].Val=A;
		Sm[Data[A].Str]=A;
	}
}

BOOLEAN SearchArray(TA_Struct S[],int Size)
{
	int A=0;
	while((S[A].Str.compare(S[Size/2].Str) !=0) && (A<Size))
	{
		A++;
	}

	return (A<Size);
}

BOOLEAN SearchMap(map<string,int> m,string Search)
{
	return (m.find(Search) == m.end());
}

void SpeedTest(void)
{
	map<string, int> MyMap;
	const int TASize=ARRAY_SIZE;
	TA_Struct TestArray[TASize]={"",0};
	double SearchTimes[3]={0};
	double PCFreq=0.0;
	__int64 StartTime=0;
	string Str;
		
	
	InsertData(TestArray,TASize,MyMap);  // Generate Data
	system("cls");
	cout << "Searching " << TASize << " elements" << endl << endl;

	cout << "Searching Map - ";
	StartTime=StartCounter(&PCFreq,1); // Start Map Search
	if(SearchMap(MyMap,TestArray[TASize/2].Str))
		{
			SearchTimes[1]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Map in ",SearchTimes[1]);
		}
			
	cout << "Binary Search - ";
	StartTime=StartCounter(&PCFreq,1); // Start Binary Search
	if (BinarySearch(TestArray, TestArray[TASize/2].Str))
		{
			SearchTimes[2]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Binary search in ",SearchTimes[2]);
		}
	
	cout << "Searching array (Linear) - ";
	StartTime=StartCounter(&PCFreq,1); // Start Array Search
	if(SearchArray(TestArray,TASize))
		{
			SearchTimes[0]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Array in ",SearchTimes[0]);
		}
	
	for(int A=0;A<3;A++)
	{
		if(SearchTimes[A]==0)
			PrintMSG("Error in search ",A);
	}

	if((SearchTimes[0] < SearchTimes[1]) && (SearchTimes[0] < SearchTimes[2]))
		Str="Array";
	else if((SearchTimes[1] < SearchTimes[0]) && (SearchTimes[1] < SearchTimes[2]))
		Str="Map";
	else
		Str="Binary";
	cout << "The " << Str << " search was the fastest" << endl;
}
