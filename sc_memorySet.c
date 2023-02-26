#include "mySimpleComputer.h"



int sc_memorySet(int address,int value)
{
	if ((address>=0) && (address<SIZE))
	{
		Memory[address]=value;
		return 0;
	}
	else
	{
		BIT_SET(flag,1);
		printf("Выход за границы памяти\n");
		return 0;
	}
	
}
