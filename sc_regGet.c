#include "mySimpleComputer.h"


int sc_regGet(int reg,int *value)
{
	if (reg>0)
	{
		*value=BIT_GET(reg_flags,reg);
		return 0;
	}
	else
	{
		BIT_SET(flag,3);
		printf("Недопустимый номер регистра\n");
		return 0;
	}
}

