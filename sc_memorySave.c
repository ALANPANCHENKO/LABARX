#include "mySimpleComputer.h"


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
