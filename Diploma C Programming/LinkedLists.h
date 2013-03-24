#include <Windows.h>
#include "Utils.h"

struct listStruct {
	int Val;
	struct listStruct *Next;
	struct listStruct *Prev;
};

void AddNode(listStruct **,int);
void AddDoubleNode(listStruct **,listStruct **,int);
void DeleteNode(listStruct **,int);
void DisplayNodes(listStruct **);
void DisplayDouble(listStruct **);
boolean SearchNodes(listStruct **,int);
listStruct* BubbleSort(listStruct **);
void Sort(listStruct **);
