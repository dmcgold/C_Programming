#include "Week 1.h"

using namespace std;

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
	int Array[5];
	int No=0;

	Pointer=&Array[0];

	for(Counter=0;Counter<5;Counter++)
	{
		printf("Enter an Integer : ");
		scanf_s("%d%*c",&No);
		Array[Counter]=No;
	}
	printf("Integers are\n ");
	for(Counter=0;Counter<5;Counter++)
	{
		printf("Array Value   %d,  ",Array[Counter]);

		printf("Pointer Value %d\n",*Pointer++);
	}
}

void Modify(int *Value)
{
	cout << "Adding 100" << endl;
	*Value=*Value+100;
}

void Exercise3(void)
{
	int *Number;
	int n=1;

	Number=&n;

	cout << "Original Number " << *Number << endl;
	Modify(Number);

	cout << "New Number " << *Number << endl;
}

void Exercise4(void)
{
	char S[20]="Hello World";
	char N[20]="";

	cout << S << endl;
	cout << N << endl;
	scopy(S,N,5);
	cout << N << endl;
}

void scopy(char *Source, char *Destination,int NoElements)
{
	int A;

	for(A=0;A<NoElements;A++)
	{
		Destination[A]=Source[A];
	}
}