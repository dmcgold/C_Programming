#include "LinkedLists.h"

using namespace std;

void AddNode(listStruct **linked_List,int Val)
{
	struct listStruct *Head=*linked_List;
	struct listStruct *Temp;

	Temp = new listStruct;
	Temp->Val=Val;
	Temp->Next=Head;
	Head=Temp;

	*linked_List=Head;
}

void AddDoubleNode(listStruct **linked_List,listStruct **Last,int Val)
{
	listStruct *Temp;

	Temp = new listStruct;
	Temp->Val=Val;
	Temp->Next = (*linked_List);
	Temp->Prev = NULL;
	if (Temp->Next != NULL)
		Temp->Next->Prev=Temp;
	if ((*linked_List) == NULL)
		(*Last)=Temp;
	(*linked_List)=Temp;
}

void DeleteNode(listStruct **linked_List,int Val)
{
	listStruct *listHead=*linked_List;
	listStruct *listPrev=*linked_List;
	listStruct *listTemp=*linked_List;

	if (listHead->Val==Val)
	{
		*linked_List=listTemp->Next;
		delete(listTemp);
		listTemp=NULL;
		return;
	}
	while ((listHead!=NULL) && (listHead->Val!=Val))
	{
		listPrev=listHead;
		listHead=listHead->Next;
	}
	listPrev->Next=listHead->Next;
	delete(listHead);
	listHead=NULL;
}

void DisplayNodes(listStruct **linked_List)
{
	listStruct *listNodes=*linked_List;

	while (listNodes)
	{
		cout << "Current Value : "<< listNodes->Val << endl;
		listNodes=listNodes->Next;
	}
}

void DisplayDouble(listStruct **linked_List)
{
	if ((*linked_List)!=NULL)
	{
		cout << (*linked_List)->Val << " ";
		DisplayDouble(&(*linked_List)->Next);
	}
}

boolean SearchNodes(listStruct **linked_List,int searchItem)
{
	while ((*linked_List != NULL) && ((*linked_List)->Val != searchItem))
	{
		linked_List=&(*linked_List)->Next;
	}
	if (((*linked_List) != NULL) && (*linked_List)->Val == searchItem)
		return TRUE;
	else
		return FALSE;
}

listStruct *BubbleSort(listStruct **head)
{
    listStruct *tmpPtr = (*head);
    listStruct *tmpNxt = (*head)->Next;

    int tmp;

    while (tmpNxt != NULL){
           while (tmpNxt != tmpPtr){
                    if (tmpNxt->Val < tmpPtr->Val){
                            tmp = tmpPtr->Val;
                            tmpPtr->Val = tmpNxt->Val;
                            tmpNxt->Val = tmp;
                    }
                    tmpPtr = tmpPtr->Next;
            }
            tmpPtr = (*head);
            tmpNxt = tmpNxt->Next;
    }
         return tmpPtr ; // Place holder
} 


void Sort(listStruct **linked_List)
{
	SYSTEMTIME  sTime,eTime,totalTime;

	cout << endl << "Sorting list" << endl;
	GetSystemTime(&sTime);
	(*linked_List)=BubbleSort(&(*linked_List));
	//(*linked_List)=BubbleSort(&(*linked_List));
	GetSystemTime(&eTime);
	totalTime=GetTotalTime(sTime,eTime);
	cout << "Sort completion time (MM:SS:Milliseconds) " << (int) totalTime.wMinute << ":"\
		<< (int) totalTime.wSecond << ":" << (long) totalTime.wMilliseconds << endl;
}