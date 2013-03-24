#include <Windows.h>
#include "Utils.h"

struct listStruct {
	int Value;
	struct listStruct *Next;
	struct listStruct *Prev;
};

void AddNode(listStruct **,int,int *);
void AddDoubleNode(listStruct **,listStruct **,int);
int DeleteNode(listStruct **,int,int);
void DisplayNodes(listStruct **);
void DisplayDouble(listStruct **);
boolean SearchNodes(listStruct **,int);
listStruct* BubbleSort(listStruct **);
listStruct *QuickSort(listStruct *, int, int);
void Sort(listStruct **,int);
