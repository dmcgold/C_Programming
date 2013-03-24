#include "Binary.h"

using namespace std;

void AddToTree(BinaryStruct **bTree, int bValue)
{
	if ( (*bTree) == NULL)
	{
		(*bTree) = new BinaryStruct;
		(*bTree)->Value=bValue;
		(*bTree)->Left=NULL;
		(*bTree)->Right=NULL;
	}
	else
	{
		if ((*bTree)->Value <= bValue)
			AddToTree( &(*bTree)->Right,bValue);
		else
			AddToTree( &(*bTree)->Left,bValue);
	}
}

void DisplayTree(BinaryStruct **bTree)
{
	if (*bTree != NULL)
	{
		DisplayTree(&(*bTree)->Left);
		cout << "Value is " << (*bTree)->Value << '\n';
		DisplayTree(&(*bTree)->Right);
	}
}

BinaryStruct **SearchTree(BinaryStruct **bTree,int bValue)
{
	BinaryStruct **tmp= bTree;

	while (*tmp != NULL)
	{
		if (bValue < (*tmp)->Value)
			tmp = &(*tmp)->Left;
		else if ((*tmp)->Value < bValue)
			tmp = &(*tmp)->Right;
		else
			break;
	}
	return tmp;
}

boolean DeleteLeaf(BinaryStruct **bTree, int bValue)
{
	BinaryStruct *bTemp;
	BinaryStruct *moveNode;
	Log("Deleting from tree",MAJOR_ERROR,OUT_TO_FILE);
	bTree=SearchTree(bTree,bValue);

	if ((*bTree)->Value != bValue)
		return FALSE;

	bTemp=(*bTree);

	if (((*bTree)->Left==NULL) && ((*bTree)->Right==NULL))
	{
		cout << "No Children found deleting Branch " << endl;
		delete (*bTree);
		*bTree = NULL;
	}
	else if (((*bTree)->Left == NULL) && ((*bTree)->Right!=NULL))
	{
		(*bTree)=(*bTree)->Right;
		cout << "No Children on left " << endl;
	}
	else if (((*bTree)->Right == NULL) && ((*bTree)->Left!=NULL))
	{
		(*bTree)=(*bTree)->Left;
		cout << "No Children on right " << endl;
	}
	else
	{
		cout << "Two children" << endl;
		bTemp=(*bTree)->Right;
		while (bTemp->Left!=NULL)
			bTemp=bTemp->Left;
		moveNode=bTemp;
		(*bTree)->Value=moveNode->Value;
		bTemp->Left=(*bTree)->Left;
		bTemp=(*bTree);
		(*bTree)=(*bTree)->Right;

		delete bTemp;
	}
	return TRUE;
}