#include "mySimpleComputer.h"


int sc_commandEncode(int command,int operand,int *value)
{
	void *cmd_ptr;
	cmd_ptr = bsearch(&command,cmd_arr,cmd_num,sizeof(int),compare);
	
	if (cmd_ptr!=NULL)
	{
		*value=(command<<7)|operand;
		return 0;
	}
	else
	{
		BIT_SET(flag,4);
		printf("Ошибочная команда\n");
		return 0;
	}
	
}
