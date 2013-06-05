#include <Windows.h>
#include "Utils.h"
#include <stdio.h>

struct listStruct {
	int Value;
	struct listStruct *Next;
};

int AddNode(listStruct **,int,int );
int DeleteNode(listStruct **,int,int);
void DisplayNodes(listStruct **);
boolean SearchNodes(listStruct **,int);
listStruct* BubbleSort(listStruct **);
int getValue(listStruct *,int);
void qSwap(listStruct *, int ,int );
void qSort(listStruct *, int ,int );
void Sort(listStruct **,int);
