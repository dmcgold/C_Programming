#include "stdafx.h"
#include "Linked Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void AddNode(Item **List,int Val)
{
	Item *Head=*List;
	Item *Temp;

	Temp = new Item;
	Temp->Val=Val;
	Temp->Next=Head;
	Head=Temp;

	*List=Head;
}

void DeleteNode(Item **List,int Val)
{
	Item *Head=*List;
	Item *Prev=*List;
	Item *temp=*List;

	if(Head->Val==Val)
	{
		*List=temp->Next;
		delete(temp);
		temp=NULL;
		return;
	}
	while((Head!=NULL) && (Head->Val!=Val))
	{
		Prev=Head;
		Head=Head->Next;
	}
	Prev->Next=Head->Next;
	delete(Head);
	Head=NULL;
}

void PrintNodes(Item **List)
{
	Item *Nodes=*List;

	while(Nodes)
	{
		cout << "Current Value :  " << Nodes->Val << endl;
		Nodes=Nodes->Next;
	}
}