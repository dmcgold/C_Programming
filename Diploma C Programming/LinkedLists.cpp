#include "LinkedLists.h"

using namespace std;

void AddNode(ListStruct **linked_List,int Val)
{
	struct ListStruct *Head=*linked_List;
	struct ListStruct *Temp;

	Temp = new ListStruct;
	Temp->Val=Val;
	Temp->Next=Head;
	Head=Temp;

	*linked_List=Head;
}

void AddDoubleNode(ListStruct **linked_List,ListStruct **Last,int Val)
{
	ListStruct *Temp;

	Temp = new ListStruct;
	Temp->Val=Val;
	Temp->Next = (*linked_List);
	Temp->Prev = NULL;
	if(Temp->Next != NULL)
		Temp->Next->Prev=Temp;
	if((*linked_List) == NULL)
		(*Last)=Temp;
	(*linked_List)=Temp;
}

void DeleteNode(ListStruct **linked_List,int Val)
{
	ListStruct *listHead=*linked_List;
	ListStruct *listPrev=*linked_List;
	ListStruct *listTemp=*linked_List;

	if(listHead->Val==Val)
	{
		*linked_List=listTemp->Next;
		delete(listTemp);
		listTemp=NULL;
		return;
	}
	while((listHead!=NULL) && (listHead->Val!=Val))
	{
		listPrev=listHead;
		listHead=listHead->Next;
	}
	listPrev->Next=listHead->Next;
	delete(listHead);
	listHead=NULL;
}

void DisplayNodes(ListStruct **linked_List)
{
	ListStruct *listNodes=*linked_List;

	while(listNodes)
	{
		cout << "Current Value : "<< listNodes->Val << endl;
		listNodes=listNodes->Next;
	}
}

void DisplayDouble(ListStruct **linked_List)
{
	if((*linked_List)!=NULL)
	{
		cout << (*linked_List)->Val << " ";
		DisplayDouble(&(*linked_List)->Next);
	}
}

boolean SearchNodes(ListStruct **linked_List,int searchItem)
{
	while((*linked_List != NULL) && ((*linked_List)->Val != searchItem))
	{
		linked_List=&(*linked_List)->Next;
	}
	if(((*linked_List) != NULL) && (*linked_List)->Val == searchItem)
		return TRUE;
	else
		return FALSE;
}

ListStruct*  InsertSort(ListStruct **linked_List)
{
	ListStruct *listStructs = *(linked_List);
	ListStruct *sortedList = NULL;

	while (listStructs != NULL)
	{
		ListStruct *listHead  = listStructs;
		ListStruct **listPrev = &sortedList;
		listStructs = listStructs->Next;

		while (TRUE)
		{
			if ((*listPrev) || ((int) listHead->Val < (int) (*listPrev)->Val ))
			{
				listHead->Next = *listPrev;
				*listPrev = listHead;
				break;
			}
			else
			{
				listPrev = &(*listPrev)->Next;
			}
		}
	}
	return sortedList;
}

void Sort(ListStruct **linked_List)
{
	SYSTEMTIME  sTime,eTime,totalTime;

	cout << endl << "Sorting list" << endl;
	GetSystemTime(&sTime);
	(*linked_List)=InsertSort(&(*linked_List));
	GetSystemTime(&eTime);
	totalTime=GetTotalTime(sTime,eTime);
	cout << "Sort completion time (MM:SS:Milliseconds) " << (int) totalTime.wMinute << ":"\
		<< (int) totalTime.wSecond << ":" << (long) totalTime.wMilliseconds << endl;
}