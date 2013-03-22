#include <iostream>
#include "Run.h"
#include "Utils.h"
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	char menuCh;
	char *mainMenu[]={"3","Linked Lists","Play with Trees","HashMaps"};
	
	srand ((unsigned int) time(NULL)); // 
	do
	{
		menuCh=displayMenu(mainMenu);
		switch (menuCh)
		{
			case '1' : runLinkedLists();break;
			case '2' : runTrees();break;
			case '3' : runHash();break;
		}
	} while (menuCh!='Q');
}