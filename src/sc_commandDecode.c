#include "mySimpleComputer.h"


int sc_commandDecode(int value,int *command,int *operand)
{
	void *correct;
	int temp,temp_cmd,temp_oper;
	
	temp=(value>>14)&1;
	if (temp==0)
	{
		temp_cmd=(value>>7) & 0x7F;
		temp_oper=value & 0x7F;
		
		correct=bsearch(&temp_cmd,cmd_arr,cmd_num,sizeof(int),compare);
		
		if (correct!=NULL)
		{
			*command=temp_cmd;
			*operand=temp_oper;
		}
		else
		{
			BIT_SET(flag,4);
			printf("Ошибочная команда\n");
			return 0;
		}
	}
		return 0;
}
