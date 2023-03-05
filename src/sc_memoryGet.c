#include "mySimpleComputer.h"


int sc_memoryGet(int address,int *value)
{
	if ((address>=0) && (address<SIZE))
	{
		*value=Memory[address];
		return 0;
	}
	else
	{
		BIT_SET(flag,1);
		printf("Выход за границы памяти\n");
		return 0;
	}
}
