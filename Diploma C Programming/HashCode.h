#include "Logs.h"
#include "Utils.h"

#define ARRAY_SIZE 100;

struct mStruct   // mStruct = Map Structure
{
	char *Key;
	int Value;
	struct mStruct *Next;
};

unsigned int HashCode(char *);
void AddNode(mStruct **,char * ,int);
int Add(char *,int,mStruct []);
boolean Find(int ,mStruct []);
boolean DeleteMap(int ,mStruct []);
