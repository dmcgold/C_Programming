#include <Windows.h>
#include "Utils.h"

struct ListStruct {
	int Val;
	struct ListStruct *Next;
	struct ListStruct *Prev;
};

void AddNode(ListStruct **,int);
void AddDoubleNode(ListStruct **,ListStruct **,int);
void DeleteNode(ListStruct **,int);
void DisplayNodes(ListStruct **);
boolean SearchNodes(ListStruct *,int );
void DisplayDouble(ListStruct **);
ListStruct* InsertSort(ListStruct **);
void Sort(ListStruct **);

