#define CREATE_LOG 0

#define TESTING		 0
#define MINOR_ERROR	 1
#define MEDIUM_ERROR 2
#define MAJOR_ERROR  3
#define OUT_TO_FILE  5
#define OUT_TO_SCR   6

char *ErrStr(int);
int Log(char * ,int, int);
