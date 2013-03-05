#include <iostream>
#include "LinkedLists.h"
#include "Week 1.h"
#include "Binary.h"
#include "Logs.h"
#include "HashCode.h"
#include <time.h>
#include <ctype.h>
#include <conio.h>

using namespace std;

void runWeek1(void)
{
	char S[20]="Hello World";
	char N[20]="";

	printf("%s\n",S);
	cout << endl << N;
	scopy(S,N,5);
	cout << endl << N;

	PressKey(" ");
}

void runLinkedLists(void)
{
	ListStruct *Data;

	Data=NULL;

	char Ch=' ';
	int No=0;	
	do
	{
		Ch=' ';
		system("cls");
		cout << "1) Add to Node"<< endl;
		cout << "2) Display Nodes" << endl;
		cout << "3) Search Nodes" << endl;
		cout << "4) Delete Nodes" << endl;
		cout << "Q) Quit" << endl;
		do
		{
			Ch=toupper(_getch());
		} while (Ch==' ');
		switch (Ch)
		{
		case '1' : {
						cout << "Adding to Nodes" << endl;
						for(int A=1; A<10; A++)
						{
							AddNode(&Data,A);
						}
						Log("Adding to trees",MinorError,Out_to_File);
					}
					break;
		case '2' : {
						DisplayNodes(&Data);
						PressKey(" ");
					}
					break;
		case '3' : {
						cout << "Enter No to search for : ";
						cin >> No;
						cout << "Found : " << No << endl;
						PressKey(" ");
					}
					break;
		case '4' : {
						cout << "Enter No to search for : ";
						cin >> No;
			
						DeleteNode(&Data,No);
					}
					break;
		}
	} while (Ch!='Q');
}	

void runTrees(void)
{
	BinaryStruct *Tree=NULL;

	char Ch=' ';
	int No=0;
	srand((int) time(NULL));
	char S[11]="";
	char Str[]="Searching for ";
	
	do
	{
		Ch=' ';
		system("cls");
		cout << "1) Add to Tree" << endl;
		cout << "2) Display Tree" << endl;
		cout << "3) Search Tree" << endl;
		cout << "4) Delete from Tree" << endl;
		cout << "Q) Quit" << endl;
		do
		{
			Ch=toupper(_getch());
		} while (Ch==' ');
		switch (Ch)
		{
		case '1' : {
						cout << "Adding to trees\n";
						// srand((int) time(NULL));
						AddToTree(&Tree, 5);
						AddToTree(&Tree, 3);
						AddToTree(&Tree, 2);
						AddToTree(&Tree, 1);
						AddToTree(&Tree, 7);
						AddToTree(&Tree, 6);
						AddToTree(&Tree, 10);
						AddToTree(&Tree, 9);
						Log("Adding to trees",MinorError,Out_to_File);
					}
					break;
		case '2' : {
						DisplayTree(&Tree);
						PressKey(" ");
					}
					break;
		case '3' : {
						cout << "Enter No to search for : ";
						cin >> No;
						cout << "Found : " << No << endl;
						PressKey(" ");
					}
					break;
		case '4' : {
						cout << "Enter No to search for : ";
						cin >> No;
						
						//itoa(No,S,10);
						Log(Str,MinorError,Out_to_File);
						if(DeleteLeaf(&Tree,No))
							cout << "Success" << endl;
						else
						{
							cout << "Failure" << endl;
							Log("Failed to find ListStruct",MajorError,Out_to_File);
						}
						PressKey(" ");
					}
					break;
		}
	} while (Ch!='Q');
}


void runHash(void)
{
	cout << "The hashcode for hello is : " << HashCode("hello") << endl;
	PressKey(" ");
}