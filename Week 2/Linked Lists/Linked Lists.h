struct ListStruct {
	int Val;
	struct ListStruct *Next;
};

typedef struct ListStruct Item;

void AddNode(Item **,int);
void DeleteNode(Item **,int);
void PrintNodes(Item **List);