#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define SECONDS		 0
#define MILLISECONDS 1
#define MICROSECONDS 2


using namespace std;

void PressKey(char *);
char GetCh(void);
SYSTEMTIME GetTotalTime(SYSTEMTIME,SYSTEMTIME);
__int64 StartCounter(double *,int);
double GetCounter(__int64 ,double );
char *RandomString(int);
char displayMenu(char *[]);