#define CreateLog 0

#define Testing		0
#define MinorError	1
#define MediumError 2
#define MajorError 3
#define Out_to_File 5
#define Out_to_Scr  6

char *ErrStr(int);
int Log(char * ,int, int);
