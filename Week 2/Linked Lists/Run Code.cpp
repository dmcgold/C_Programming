#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "Linked Lists.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Item *Data;

	Data=NULL;

	for(int A=1; A<10; A++)
	{
		AddNode(&Data,A);
	}
	
	PrintNodes(&Data);
	scanf_s("%*c");
	return 0;
}

