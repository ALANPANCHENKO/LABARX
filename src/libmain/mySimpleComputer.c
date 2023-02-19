#include "mySimpleComputer.h"

int sc_memoryInit()
{
	for (int i=0;i<SIZE;i++)
		Memory[i]=0;
		
	return 0;
}

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

int sc_memorySave(char *filename)
{
	FILE *f;
	f=fopen(filename, "wb");
	
	int temp;
	
	if (f==NULL)
		return -1;
	
	temp=fwrite(Memory,sizeof(*Memory)*100,1,f);
	fclose(f);
	
	if (temp!=1)
		return -1;
	else
		return 0;
}

int sc_memoryLoad(char *filename)
{
	FILE *f;
	
	int k;
	
	f=fopen(filename,"rb");
	if (f == NULL)
		return -1;
	
	k=fread(Memory,sizeof(*Memory)*100,1,f);
	
	for (int i=0;i<SIZE;i++)
		Memory[i]= Memory[i] & 0x7FFF;
	fclose(f);
	if (k!=1)
		return -1;
	else
		return 0;
}

int sc_regInit()
{
	reg_flags=0;
	return 0;
}

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

int compare(const void *a,const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}
