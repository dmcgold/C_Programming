#include "HashCode.h"

using namespace std;

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
   {
		cout << "Found " << SearchItem << " at element " << Last << endl;
		return true;
   }
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
		Sm[Data[A].Str]=HashCode(S);
	}
}

BOOLEAN SearchArray(TA_Struct S[],int Size,string Search)
{
	int A=0;
	while((S[A].Str.compare(Search) !=0) && (A<Size))
	{
		A++;
	}
	if(A<Size)
		cout << "Found " << Search << " at element " << A << endl;
	return (A<Size);
}

BOOLEAN SearchMap(map<string,int> m,string Search)
{
	map<string,int>::iterator Key = m.find(Search);
	boolean Found=(Key != m.end());

	if(Found)
		cout << "Found " << Search << " with Key " << Key->second;
	return Found;
}

void SpeedTest(void)
{
	map<string, int> MyMap;
	const int TASize=ARRAY_SIZE;
	TA_Struct TestArray[TASize]={"",0};
	double SearchTimes[3]={100000};
	double PCFreq=0.0;
	__int64 StartTime=0;
	string Str;
		
	
	InsertData(TestArray,TASize,MyMap);  // Generate Data
	Str=TestArray[TASize-1].Str;

	system("cls");
	cout << "Searching " << TASize << " elements for " << Str << endl << endl;

	cout << "Searching Map - ";
	StartTime=StartCounter(&PCFreq,1); // Start Map Search
	if(SearchMap(MyMap,Str))
		{
			SearchTimes[1]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Map in ",SearchTimes[1]);
		}
	else
		cout << "Not Found" << endl << endl;
			
	cout << "Binary Search - ";
	StartTime=StartCounter(&PCFreq,1); // Start Binary Search
	if (BinarySearch(TestArray, Str))
		{
			SearchTimes[2]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Binary search in ",SearchTimes[2]);
		}
	else
		cout << "Not Found" << endl << endl;
	cout << "Searching array (Linear) - ";
	StartTime=StartCounter(&PCFreq,1); // Start Array Search
	if(SearchArray(TestArray,TASize,Str))
		{
			SearchTimes[0]=GetCounter(StartTime, PCFreq);
			PrintMSG("Found string in Array in ",SearchTimes[0]);
		}
	else
		cout << "Not Found" << endl << endl;	

	if((SearchTimes[0] < SearchTimes[1]) && (SearchTimes[0] < SearchTimes[2]))
		Str="Array";
	else if((SearchTimes[1] < SearchTimes[0]) && (SearchTimes[1] < SearchTimes[2]))
		Str="Map";
	else
		Str="Binary";
	cout << "The " << Str << " search was the fastest" << endl;
}
