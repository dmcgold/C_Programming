#include <Windows.h>
#include "Utils.h"

struct listStruct {
	int Value;
	struct listStruct *Next;
};

void AddNode(listStruct **,int,int *);
int DeleteNode(listStruct **,int,int);
void DisplayNodes(listStruct **);
boolean SearchNodes(listStruct **,int);
listStruct* BubbleSort(listStruct **);
listStruct *QuickSort(listStruct *, int, int);
void Sort(listStruct **,int);
