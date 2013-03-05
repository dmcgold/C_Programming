#include "HashCode.h"
#include <string.h>
#include <iostream>
#include <assert.h>

using namespace std;

long HashCode(string Str)
{
	long Hash = 0;
	int Length=Str.length();	

	if (!Str.empty()) 
	{        
		for (int A = 0; A < Length; A++) 
		{
			Hash = 31*Hash + (int) Str[A] + ((int) Str[A] >> 4);
		}
	}
	return Hash;
}

void HashMaps(void)
{
	std::map<string, int> m;
	m["hello"] = 1;
	m["how"] = 2;
	m["are"] = 3;
	m["you"] = 4;
	m["world"] = 10;
	
	if (m.find("world") != m.end())
	  cout << endl << "map contains key world! at " << m["world"] << endl;

	cout << m["hello"] << endl;
	cout << m["how"] << endl;
	cout << m["are"] << endl;
	cout << m["you"] << endl;

	map<string, int>::iterator i = m.find("hello");
	assert(i != m.end());
	cout << i->first << " = 1st Key: " <<  " Value is: " << i->second << endl;
}
