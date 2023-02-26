#include "mySimpleComputer.h"


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

