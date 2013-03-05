#include "Binary.h"

using namespace std;


void AddToTree(BinaryStruct **Tree, int Value)
{
	if( (*Tree) == NULL)
	{
		(*Tree) = new BinaryStruct;
		(*Tree)->Value=Value;
		(*Tree)->Left=NULL;
		(*Tree)->Right=NULL;
	}
	else
	{
		if((*Tree)->Value <= Value)
			AddToTree( &(*Tree)->Right,Value);
		else
			AddToTree( &(*Tree)->Left,Value);
	}
}

void DisplayTree(BinaryStruct **Tree)
{
	if (*Tree != NULL)
	{
		DisplayTree(&(*Tree)->Left);
		cout << "Value is " << (*Tree)->Value << '\n';
		DisplayTree(&(*Tree)->Right);
	}
}

BinaryStruct **SearchTree(BinaryStruct **Tree,int No)
{
	if (*Tree != NULL)
	{
		SearchTree(&(*Tree)->Left,No);
		if(No==(*Tree)->Value)
			return &(*Tree);
		SearchTree(&(*Tree)->Right,No);
	}
	return Tree;
}

boolean DeleteLeaf(BinaryStruct **Tree, int Value)
{
	BinaryStruct *Temp;
	BinaryStruct *MoveNode;
	Log("Deleting from tree",MajorError,Out_to_File);
	Tree=SearchTree(Tree,Value);

	if (((*Tree)==NULL) || ((*Tree)->Value != Value))
		return FALSE;

	Temp=(*Tree);

	if(((*Tree)->Left==NULL) && ((*Tree)->Right==NULL))
	{
		cout << "No Children found deleting Branch " << endl;
		delete (*Tree);
		*Tree = NULL;
	}
	else if(((*Tree)->Left == NULL) && ((*Tree)->Right!=NULL))
	{
		(*Tree)=(*Tree)->Right;
		cout << "No Children on left " << endl;
	}
	else if(((*Tree)->Right == NULL) && ((*Tree)->Left!=NULL))
	{
		(*Tree)=(*Tree)->Left;
		cout << "No Children on right " << endl;
	}
	else
	{
		cout << "Two children" << endl;
		Temp=(*Tree)->Right;
		while(Temp->Left!=NULL)
			Temp=Temp->Left;
		MoveNode=Temp;
		(*Tree)->Value=MoveNode->Value;
		Temp->Left=(*Tree)->Left;
		Temp=(*Tree);
		(*Tree)=(*Tree)->Right;

		delete Temp;
	}
	return TRUE;
}