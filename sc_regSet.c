#include "mySimpleComputer.h"


int sc_regSet(int reg,int value)
{
	if (reg>0)
	{
		if (value==1)
		{
			BIT_SET(reg_flags,reg);
		}
		else if (value==0)
		{
			BIT_UNSET(reg_flags,reg);
		}
		else
		{
			BIT_SET(flag,2);
			printf("Недопустимое значение регистра\n");
			return 0;
		}
	}
	else
	{
		BIT_SET(flag,3);
		printf("Недопустимый номер регистра\n");
	}
	return 0;
}
