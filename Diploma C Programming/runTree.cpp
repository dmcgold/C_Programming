#include "Binary.h"
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Logs.h"



using namespace std;

int main()
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
						
						itoa(No,S,10);
						strcat(Str,S);
						Log(Str,MinorError,Out_to_File);
						if(DeleteLeaf(&Tree,No))
							cout << "Success" << endl;
						else
						{
							cout << "Failure" << endl;
							Log("Failed to find item",MajorError,Out_to_File);
						}
						PressKey(" ");
				   }
		}
	} while (Ch!='Q');
}