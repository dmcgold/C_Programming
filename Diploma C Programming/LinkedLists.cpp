#include "LinkedLists.h"

using namespace std;

int AddNode(listStruct **linkedList,int Value,int sizeOfList)
{
	struct listStruct *Head=*linkedList;
	struct listStruct *Temp;

	Temp = new listStruct;
	Temp->Value=Value;
	Temp->Next=Head;
	Head=Temp;
	*linkedList=Head;
	sizeOfList++;
	return sizeOfList;
}

int DeleteNode(listStruct **linked_List,int searchItem,int nodeCount)
{
	listStruct *listHead=*linked_List;
	listStruct *listTemp=*linked_List;

	if(listHead!=NULL)
	{
		if(listHead->Value==searchItem)
		{
			*linked_List=listTemp->Next;
			delete(listTemp);
			listTemp=NULL;
			nodeCount--;
			return nodeCount;
		}
		nodeCount=DeleteNode(&(*linked_List)->Next,searchItem,nodeCount);
	}
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

int getValue(listStruct *head,int v)
{
	v--;
	for(int a=0;a<v;a++)
		head=head->Next;
	return head->Value;
}

void qSwap(listStruct *head,int left,int right)
{
	listStruct *tmpHead=head;
	int a=getValue(head,left);
	int b=getValue(head,right);
	if(left==right)
		return;
	while((tmpHead->Value !=a) && (tmpHead->Next!='\0'))
		tmpHead=tmpHead->Next;
	tmpHead->Value=b;
	tmpHead=tmpHead->Next;
	while((tmpHead->Value !=b) && (tmpHead->Next!='\0'))
		tmpHead=tmpHead->Next;
	tmpHead->Value=a;
	head=tmpHead;
}

void qSort(listStruct *head, int l, int u)
{
	int i,m;

	if(l>=u) return;
	m=l;
	for(i=l+1;i<=u;i++)
		if(getValue(head,i) < getValue(head,l))
			qSwap(head,++m ,i);
	qSwap(head,l,m);
	qSort(head,l,m-1);
	qSort(head,m+1,u);
}

void Sort(listStruct **linkedList,int sizeOfList)
{
	__int64 startCounter;
	double endCounter;
	double pcFreq=0.0;
	char counterStr[10];

	strcpy(counterStr,"");
	cout << endl << "Sorting list" << endl;
	startCounter=StartCounter(&pcFreq,SECONDS);
	//(*linkedList)=BubbleSort(&(*linkedList));
	//(*linkedList)=QuickSort((*linkedList),0,sizeOfList);
	qSort((*linkedList),0,sizeOfList);
	endCounter=GetCounter(startCounter,pcFreq);
	sprintf(counterStr,"%4.5f",endCounter);
	cout << endl << "Sort completed in " << counterStr << " seconds" << endl << endl;
}