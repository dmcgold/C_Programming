// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Exercise1(void);
void Exercise2(void);
void Exercise3(void);
void Modify(int *);
void scopy(char *Source, char *Destination,int NoElements);

int _tmain(int argc, _TCHAR* argv[])
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

void Exercise1(void)
{
	int *No1;
	long *No2;
	short *No3;
	short int *No4;
	long int *No5;
	float *No6;
	double *No7;
	signed int *No8;
	int Number1=10;
	long Number2=20;
	short Number3=30;
	short int Number4=40;
	long int Number5=50;
	float Number6=60;
	double Number7=70;
	signed int Number8=80;
	
	No1=&Number1;
	No2=&Number2;
	No3=&Number3;
	No4=&Number4;
	No5=&Number5;
	No6=&Number6;
	No7=&Number7;
	No8=&Number8;

	printf("           \tLocation \t Value\n");
	printf("Int Value = \t%p \t %d\n",(void *)&Number1,*No1);
	printf("Long Value = \t%p \t %d\n",(void *)&Number2,*No2);
	printf("Short Value = \t%p \t %d\n",(void *)&Number3,*No3);
	printf("Short Int = \t%p \t %d\n",(void *)&Number4,*No4);
	printf("Long Int  = \t%p \t %d\n",(void *)&Number5,*No5);
	printf("float Value = \t%p \t %f\n",(void *)&Number6,*No6);
	printf("Double = \t%p \t %f\n",(void *)&Number7,*No7);
	printf("Signed Int = \t%p \t %d\n",(void *)&Number8,*No8);
}

void Exercise2(void)
{
	int Counter;
	int *Pointer;
	int Array[10];
	int No=0;

	Pointer=&Array[0];

	for(Counter=0;Counter<10;Counter++)
	{
		printf("Enter an Integer : ");
		scanf_s("%d%*c",&No);
		Array[Counter]=No;
	}
	printf("Integers are\n ");
	for(Counter=0;Counter<10;Counter++)
	{
		printf("Array Value   %d,  ",Array[Counter]);
		
		printf("Pointer Value %d\n",*Pointer++);
	}
}

void Exercise3(void)
{
	int *Number;
	int n=1;

	Number=&n;

	printf("Original Number %d\n",*Number);
	Modify(Number);
	
	printf("New Number %d\n",*Number);
}

void Modify(int *Value)
{
	printf("Adding 100\n");
	*Value=*Value+100;
}

void scopy(char *Source, char *Destination,int NoElements)
{
	int A;

	for(A=0;A<NoElements;A++)
	{
		Destination[A]=Source[A];
	}
}