#include <Windows.h>
#include <iostream>
#include "Logs.h"
#include "Utils.h"

struct binaryStruct
{
	int Value;
	struct binaryStruct *Left;
	struct binaryStruct *Right;
};

void AddToTree(binaryStruct **, int);
void DisplayTree(binaryStruct **);
binaryStruct **SearchTree(binaryStruct **,int);
boolean DeleteLeaf (binaryStruct **,int);
