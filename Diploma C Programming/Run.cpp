#include <iostream>
#include "LinkedLists.h"
#include "Week 1.h"
#include "Binary.h"
#include "Logs.h"
#include "HashCode.h"
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;

void runWeek1(void)
{
	char Ch;
	do
	{
		Ch=' ';
		system("cls");
		cout << "1) Exercise 1"<< endl;
		cout << "2) Exercise 2" << endl;
		cout << "3) Exercise 3" << endl;
		cout << "4) Exercise 4" << endl;
		cout << "Q) Quit" << endl;
		do
		{
			Ch=toupper(_getch());
		} while (Ch==' ');
		switch (Ch)
		{
		case '1' : {
			Exercise1();
			PressKey(" ");
				   }
				   break;
		case '2' : {
			Exercise2();
			PressKey(" ");
				   }
				   break;
		case '3' : {
			Exercise3();
			PressKey(" ");
				   }
				   break;
		case '4' : {
			Exercise4();
			PressKey(" ");
				   }
				   break;
		}
	} while (Ch!='Q');
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
		cout << "5) Sort Nodes" << endl;
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
			Log("Adding to trees",MINOR_ERROR,OUT_TO_FILE);
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
			if(SearchNodes(&Data,No))
				cout << "Found : " << No << endl;
			else
				cout << No << " Not found"  << endl;
			PressKey(" ");
				   }
				   break;
		case '4' : {
			cout << "Enter No to search for : ";
			cin >> No;

			DeleteNode(&Data,No);
				   }
				   break;
		case '5' : {
			cout << "Sorting" << endl;
			InsertSort(&Data);
			cout << "Done" << endl;
				   }
		}
	} while (Ch!='Q');
}

void runTrees(void)
{
	BinaryStruct *Tree=NULL;
	BinaryStruct *tmp;

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
		Ch=GetCh();
		switch (Ch)
		{
		case '1' : {
			cout << "Adding to trees\n";
			AddToTree(&Tree, 5);
			AddToTree(&Tree, 3);
			AddToTree(&Tree, 2);
			AddToTree(&Tree, 1);
			AddToTree(&Tree, 7);
			AddToTree(&Tree, 6);
			AddToTree(&Tree, 10);
			AddToTree(&Tree, 9);
			Log("Adding to trees",MINOR_ERROR,OUT_TO_FILE);
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
			tmp=(*SearchTree(&Tree,No));
			if(tmp!=NULL)
				cout << "Found : " << No << endl;
			else
				cout << No << " not found" << endl;
			PressKey(" ");
				   }
				   break;
		case '4' : {
			cout << "Enter No to search for : ";
			cin >> No;
			Log(Str,MINOR_ERROR,OUT_TO_FILE);
			if(DeleteLeaf(&Tree,No))
				cout << "Success" << endl;
			else
			{
				cout << "Failure" << endl;
				Log("Failed to find ListStruct",MAJOR_ERROR,OUT_TO_FILE);
			}
			PressKey(" ");
				   }
				   break;
		}
	} while (Ch!='Q');
}

void runHash(void)
{
	int const Size=ARRAY_SIZE;
	mStruct hashMap[Size]={"",0,NULL};
	char *Str[]={"Apple","Oranges","Pears","Apple","Apple","Pear"}; // 2 apples
	int sizeOfStr=sizeof(Str) / sizeof(int);
	int Hash;
	printf("Adding Data to Map\n");

	for(int A=0;A<sizeOfStr;A++)
	{
		printf("Adding %s \n",Str[A]);
		Add(Str[A],A,hashMap);
	}
	for(int A=0;A<sizeOfStr;A++)
	{
		printf("Search for %s\n",Str[A]);
		Hash=Find(Str[A],hashMap);
		if(Hash!=0)
		{
			printf("Found key %s at %d\n",Str[A], Hash);
		}
	}
	PressKey("Done ....");
}