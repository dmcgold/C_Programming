#include "Week 1.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

	char S[20]="Hello World";
	char N[20]="";

	printf("%s\n",S);
	printf("%s\n",N);
	scopy(S,N,5);
	printf("%s\n",N);

	printf("\nPress Return to end");
	scanf_s("%*c");
	return 0;
}