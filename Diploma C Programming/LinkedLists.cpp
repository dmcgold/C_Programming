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

boolean SearchNodes(ListStruct *Nodes,int SearchItem)
{
	boolean Found = false;

	while((Nodes) && (!Found))
	{		
		Found = (Nodes->Val == SearchItem);
		Nodes=Nodes->Next;
	}
	return Found;
}
void DisplayDouble(ListStruct **List)
{
	if((*List)!=NULL)
	{
		cout << (*List)->Val << " ";
		DisplayDouble(&(*List)->Next);
	}
}

//void insertionSort(int arr[], int length) {
//
//      int i, j, tmp;
//
//      for (i = 1; i < length; i++) {
//
//            j = i;
//
//            while (j > 0 && arr[j - 1] > arr[j]) {
//
//                  tmp = arr[j];
//
//                  arr[j] = arr[j - 1];
//
//                  arr[j - 1] = tmp;
//
//                  j--;
//
//            }
//
//      }
//
//}
//int insertionsort(int *arr,int n)
//05	{
//06	    int i,j,temp;
//07	for(i=1;i<n;i++)
//08	    {
//09	        temp=*(arr+i);
//10	        j=i-1;
//11	        while(temp<*(arr+j)&&j>=0)
//12	        {
//13	            *(arr+(j+1))=*(arr+j);
//14	            j--;
//15	        }
//16	        *(arr+(j+1))=temp;
//17	    }
//18	    return 0;
//19	}
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
			if ((&(*Prev)) || ((int) Head->Val < (int) (*Prev)->Val ))
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
	double TotalTime;
	__int64 StartTime;
	double PCFreq=0.0;

	cout << endl << "Sorting list" << endl;

	StartTime = StartCounter(&PCFreq,1);

	(*List)=InsertSort(&(*List)); 
	
	TotalTime=GetCounter(StartTime ,PCFreq );

	cout << "Sort completion time (Milliseconds) " << TotalTime << endl;
	PressKey(" ");
}
