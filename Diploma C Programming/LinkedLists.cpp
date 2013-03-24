#include "LinkedLists.h"

using namespace std;

void AddNode(listStruct **linkedList,int Value,int *sizeOfList)
{
	struct listStruct *Head=*linkedList;
	struct listStruct *Temp;

	Temp = new listStruct;
	Temp->Value=Value;
	Temp->Next=Head;
	Head=Temp;
	sizeOfList++;
	*linkedList=Head;
}

void AddDoubleNode(listStruct **linkedList,listStruct **last,int value)
{
	listStruct *Temp;

	Temp = new listStruct;
	Temp->Value=value;
	Temp->Next = (*linkedList);
	Temp->Prev = NULL;
	if (Temp->Next != NULL)
		Temp->Next->Prev=Temp;
	if ((*linkedList) == NULL)
		(*last)=Temp;
	(*linkedList)=Temp;
}

int DeleteNode(listStruct **linked_List,int searchItem,int nodeCount)
{
	listStruct *listHead=*linked_List;
	listStruct *listTemp=*linked_List;

	if(listHead->Value==searchItem)
	{
		*linked_List=listTemp->Next;
		delete(listTemp);
		listTemp=NULL;
		nodeCount--;
		return nodeCount;
	}
	nodeCount=DeleteNode(&(*linked_List)->Next,searchItem,nodeCount);
	return nodeCount;
}

void DisplayNodes(listStruct **linkedList)
{
	listStruct *listNodes=*linkedList;

	while (listNodes != NULL)
	{
		cout << "Current Value : "<< listNodes->Value << endl;
		listNodes=listNodes->Next;
	}
}

void DisplayDouble(listStruct **linkedList)
{
	if ((*linkedList)!=NULL)
	{
		cout << (*linkedList)->Value << " ";
		DisplayDouble(&(*linkedList)->Next);
	}
}

boolean SearchNodes(listStruct **linkedList,int searchItem)
{
	while ((*linkedList != NULL) && ((*linkedList)->Value != searchItem))
	{
		linkedList=&(*linkedList)->Next;
	}
	if (((*linkedList) != NULL) && (*linkedList)->Value == searchItem)
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
                    if (tmpNxt->Value < tmpPtr->Value){
                            tmp = tmpPtr->Value;
                            tmpPtr->Value = tmpNxt->Value;
                            tmpNxt->Value = tmp;
                    }
                    tmpPtr = tmpPtr->Next;
            }
            tmpPtr = (*head);
            tmpNxt = tmpNxt->Next;
    }
         return tmpPtr ; // Place holder
} 


int get_lValue(listStruct *head, int l)
{
    while(head && l) {
        head = head->Next;
        l--;
    }
    if (head != NULL)
        return head->Value;
    else
        return -1;
}

void swap(listStruct *head, int i, int j)
{
    listStruct *tmp = head;
    int tmpiValue;
    int tmpjValue;
    int ti = i;
    while(tmp && i) {
        i--;
        tmp = tmp->Next;
    }
    tmpiValue = tmp->Value;
    tmp = head;
    while(tmp && j) {
        j--;
        tmp = tmp->Next;
    }
    tmpjValue = tmp->Value;
    tmp->Value = tmpiValue;
    tmp = head;
    i = ti;
    while(tmp && i) {
        i--;
        tmp = tmp->Next;
    }
    tmp->Value = tmpjValue;
}


listStruct *QuickSort(listStruct *head, int l, int r)
{
    int i, j;
    int jValue;
    int pivot;
    i = l + 1;
    if (l + 1 < r) {
        pivot = get_lValue(head, l);
        for (j = l + 1; j <= r; j++) {
            jValue = get_lValue(head, j);
            if (jValue < pivot && jValue != -1) {
                swap(head, i, j);
                i++;
            }
        }
        swap(head, i - 1, l);
        QuickSort(head, l, i);
        QuickSort(head, i, r);
    }
    return head;
}


void Sort(listStruct **linkedList,int sizeOfList)
{
	__int64 startCounter;
	double endCounter;
	double pcFreq=0.0;

	cout << endl << "Sorting list" << endl;
	startCounter=StartCounter(&pcFreq,SECONDS);
	//(*linkedList)=BubbleSort(&(*linkedList));
	(*linkedList)=QuickSort((*linkedList),0,sizeOfList);
	
	endCounter=GetCounter(startCounter,pcFreq);
	cout << endl << "Sort completion time (Seconds) : " << endCounter << endl;
}