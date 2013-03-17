#include "LinkedLists.h"

using namespace std;

void AddNode(ListStruct **List,int Val)
{
	struct ListStruct *Head=*List;
	struct ListStruct *Temp;

	Temp = new ListStruct;
	Temp->Val=Val;
	Temp->Next=Head;
	Head=Temp;

	*List=Head;
}

void AddDoubleNode(ListStruct **List,ListStruct **Last,int Val)
{
	ListStruct *Temp;

	Temp = new ListStruct;
	Temp->Val=Val;
	Temp->Next = (*List);
	Temp->Prev = NULL;
	if(Temp->Next != NULL)
		Temp->Next->Prev=Temp;
	if((*List) == NULL)
		(*Last)=Temp;
	(*List)=Temp;
}

void DeleteNode(ListStruct **List,int Val)
{
	ListStruct *Head=*List;
	ListStruct *Prev=*List;
	ListStruct *temp=*List;

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

void DisplayNodes(ListStruct **List)
{
	ListStruct *Nodes=*List;

	while(Nodes)
	{
		cout << "Current Value : "<< Nodes->Val << endl;
		Nodes=Nodes->Next;
	}
}

void DisplayDouble(ListStruct **List)
{
	if((*List)!=NULL)
	{
		cout << (*List)->Val << " ";
		DisplayDouble(&(*List)->Next);
	}
}

boolean SearchNodes(ListStruct **List,int No)
{
	while((*List != NULL) && ((*List)->Val != No))
	{
		List=&(*List)->Next;
	}
	if(((*List) != NULL) && (*List)->Val == No)
		return TRUE;
	else
		return FALSE;
}

ListStruct*  InsertSort(ListStruct **List)
{
	ListStruct *ListStructs = *(List);
	ListStruct *Sorted = NULL;

	while (ListStructs != NULL)
	{
		ListStruct *Head  = ListStructs;
		ListStruct **Prev = &Sorted;
		ListStructs = ListStructs->Next;

		while (TRUE)
		{
			if ((*Prev) || ((int) Head->Val < (int) (*Prev)->Val ))
			{
				Head->Next = *Prev;
				*Prev = Head;
				break;
			}
			else
			{
				Prev = &(*Prev)->Next;
			}
		}
	}
	return Sorted;
}

void Sort(ListStruct **List)
{
	SYSTEMTIME  STime,ETime,TotalTime;

	cout << endl << "Sorting list" << endl;
	GetSystemTime(&STime);
	(*List)=InsertSort(&(*List));
	GetSystemTime(&ETime);
	TotalTime=GetTotalTime(STime,ETime);
	cout << "Sort completion time (MM:SS:Milliseconds) " << (int) TotalTime.wMinute << ":"\
		<< (int) TotalTime.wSecond << ":" << (long) TotalTime.wMilliseconds << endl;
}