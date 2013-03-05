#include "HashCode.h"
#include <string.h>

long HashCode(char *Str)
{
		long Hash = 0;
		int Length = strlen(Str);
		if (Length > 0) 
		{        
			for (int A = 0; A < Length; A++) 
			{
				Hash = 31*Hash + (int) Str[A] + ((int) Str[A] >> 4);
			}
		}
       return Hash;
}
