#include <map>
#include <string>
#include <Windows.h> 
#include "Logs.h"
#include "Utils.h"

#define ARRAY_SIZE 6000;

struct TA_Struct {         	   
	string Str;
	int Val;      
}; 

long HashCode(string);
BOOLEAN BinarySearch(TA_Struct *,string);
void PrintMSG(string,double);
void InsertData(TA_Struct Data[],int Size,map<string,int> Sm);
BOOLEAN SearchArray(TA_Struct *,int);
BOOLEAN SearchMap(map<string,int> ,string);
void HashMaps(void);

