#include <Windows.h>
#include <iostream>
#include "Logs.h"
#include "Utils.h"

struct BinaryStruct
{
	int Value;
	struct BinaryStruct *Left;
	struct BinaryStruct *Right;
};

void AddToTree(BinaryStruct **, int);
void DisplayTree(BinaryStruct **);
BinaryStruct **SearchTree(BinaryStruct **Tree,int No);
boolean DeleteLeaf (BinaryStruct **Tree,int No);
