#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void PressKey(char *);
char GetCh(void);
SYSTEMTIME GetTotalTime(SYSTEMTIME,SYSTEMTIME);
__int64 StartCounter(double *,int);
double GetCounter(__int64 ,double );
char *randomString(int);
