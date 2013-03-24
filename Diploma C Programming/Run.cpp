#include "Run.h"

using namespace std;

void runLinkedLists(void)
{
	listStruct *listData;
	char *listsMenu[]={"5","Add to Node","Display Nodes","Search Nodes","Delete Nodes","Sort Nodes"};
	listData=NULL;

	char getMenuChoice=' ';
	int searchValue=0;
	do
	{
		getMenuChoice=displayMenu(listsMenu);
		switch (getMenuChoice)
		{
			case '1' : 
				{
					cout << "Adding to Nodes" << endl;
					for (int A=1; A<10; A++)
					{
						AddNode(&listData,A);
					}
					Log("Adding to trees",MINOR_ERROR,OUT_TO_FILE);
				}
				break;
			case '2' : 
			{
				DisplayNodes(&listData);
				PressKey(" ");
			}
			break;
			case '3' : 
			{
				cout << "Enter No to search for : ";
				cin >> searchValue;
				if (SearchNodes(&listData,searchValue))
					cout << "Found : " << searchValue << endl;
				else
					cout << searchValue << " Not found"  << endl;
				PressKey(" ");
			}
			break;
			case '4' : 
			{
				cout << "Enter No to search for : ";
				cin >> searchValue;
				DeleteNode(&listData,searchValue);
			}
			break;
			case '5' : 
			{
				cout << "Sorting" << endl;
				Sort(&listData);
				cout << "Done" << endl;
			}
			break;
		}
	} while (getMenuChoice!='Q');
}

void runTrees(void)
{
	BinaryStruct *bTree=NULL;
	BinaryStruct *tmp;
	
	char getMenuChoice=' ';
	char *treeMenu[]={"4","Add to tree","Display Tree","Search Tree","Delete from Tree"};
	int searchValue=0;
	srand((int) time(NULL));
	
	do
	{
		getMenuChoice=displayMenu(treeMenu);
		switch (getMenuChoice)
		{
			case '1' : 
			{
				cout << "Adding to trees\n";
				AddToTree(&bTree, 5);
				AddToTree(&bTree, 3);
				AddToTree(&bTree, 2);
				AddToTree(&bTree, 1);
				AddToTree(&bTree, 7);
				AddToTree(&bTree, 6);
				AddToTree(&bTree, 10);
				AddToTree(&bTree, 9);
				Log("Adding to trees",MINOR_ERROR,OUT_TO_FILE);
			}
			break;
			case '2' : 
			{
				DisplayTree(&bTree);
				PressKey(" ");
			}
			break;
			case '3' : 
			{
				cout << "Enter No to search for : ";
				cin >> searchValue;
				tmp=(*SearchTree(&bTree,searchValue));
				if (tmp!=NULL)
					cout << "Found : " << searchValue << endl;
				else
					cout << searchValue << " not found" << endl;
				PressKey(" ");
			}
			break;
			case '4' : 
			{
				cout << "Enter No to search for : ";
				cin >> searchValue;
				Log("Searching for data",MINOR_ERROR,OUT_TO_FILE);
				if (DeleteLeaf(&bTree,searchValue))
					cout << "Success" << endl;
				else
				{
					cout << "Failure" << endl;
					Log("Failed to find listStruct",MAJOR_ERROR,OUT_TO_FILE);
				}
				PressKey(" ");
			}
			break;
		}
	} while (getMenuChoice!='Q');
}

void runHash(void)
{
	int const size=ARRAY_SIZE;
	mStruct hashMap[size]={"",0,NULL};
	char *str[]={"Apple","Oranges","Pears","Apple","Apple","Pear"}; // 2 apples
	char *hashMenu[]={"3","Add to Map","Search Map","Delete from Map"};
	int sizeOfStr=sizeof(str) / sizeof(int);
	int hashInt;
	char getMenuChoice=' ';
	char getStr[100];

	do
	{
		getMenuChoice=displayMenu(hashMenu);
		switch (getMenuChoice)
		{
			case '1' : 
			{
				printf("\nCreate random strings or use some fruit or Enter a String (R/F/O) : ");
				switch(GetCh())
				{
					case 'R' : 
					{
						printf("\nCreating %d random 10 character words\n",size);
						for (int A=0;A<size;A++)
						{
							strcpy(getStr,RandomString(10));
							printf("\nAdding %s \n",getStr);
							Add(getStr,A,hashMap);
						}
					}
					break;
					case 'F' : 
					{
						for (int A=0;A<sizeOfStr;A++)
						{
							printf("\nAdding %s \n",str[A]);
							Add(str[A],A,hashMap);
						}
					}
					break;
					case 'O' : 
					{
						printf("\nEnter a string : ");
						gets(getStr);
						Add(getStr,10,hashMap);
					}
					break;			
				}
				PressKey("\nDone adding items");
			}
			break;
			case '2' : 
				{
					printf("\nEnter a string to search for : ");
					gets(getStr);		
					printf("\nSearching for %s\n",getStr);
					hashInt=Find(HashCode(getStr),hashMap);
					if (hashInt!=0)
					{
						printf ("\nFound item %s \n",getStr);
					}
					else
						printf ("\nFailed to find %s \n ",getStr);
					PressKey(" ");
				}
				break;
			case '3' : 
				{
					printf("\nEnter a string to search for : ");
					gets(getStr);		
					printf("\nDeleting %s from Map\n",getStr);
					if (DeleteMap(HashCode(getStr),hashMap))
						PressKey("\nSuccessfully deleted item(s) from Map");
					else
						PressKey("\nDeletion was unsuccessful....");
			   }
				break;
		} // End Switch
	} while (getMenuChoice!='Q');
}