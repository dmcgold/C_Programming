#include <iostream>
#include "Run.h"
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
	char Ch;

	do
	{
		Ch=' ';
		system("cls");
		cout << "Select program to run" << endl;
		cout << "_____________________" << endl;

		cout << "1) Week 1" << endl;
		cout << "2) Linked Lists" << endl;
		cout << "3) Play with Trees" << endl;
		cout << "4) HashCodes/HashMaps" << endl;
		cout << "Q) Quit" << endl;
		do
		{
			Ch=toupper(_getch());
		} while (Ch==' ');
		switch (Ch)
		{
			case '1' : runWeek1();break;
			case '2' : runLinkedLists();break;
			case '3' : runTrees();break;
			case '4' : runHash();break;				
		}
	} while (Ch!='Q');
}
