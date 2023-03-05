#include "mySimpleComputer.h"



int main()
{
	int a=0;
	int b=0;
	int c=0;
	
	sc_memoryInit();
	for (int i=0;i<100;i++)
		printf("%d ",Memory[i]);
	sc_memorySet(5,1);
	printf("\n%d\n",Memory[5]);
	
	sc_memoryGet(5,&a);
	printf("%d\n",a);
	
	sc_memoryGet(160,&a);
	
	sc_memorySave("1.txt");
	sc_memoryInit();
	for (int i=0;i<100;i++)
		printf("%d ",Memory[i]);
	
	sc_memoryLoad("1.txt");
	
	printf("\n Load memory: \n");
	for (int i=0;i<100;i++)
		printf("%d ",Memory[i]);
	printf("\n");
	
	sc_regInit();
	printf("%d\n",reg_flags);
	sc_regSet(3,1);
	printf("%d\n",reg_flags);
	sc_regGet(3,&a);
	printf("%d\n",a);
	
	a=0;
	
	sc_commandEncode(16,7,&a);
	printf("%d\n",a);
	sc_commandDecode(a,&b,&c);
	
	printf("%d  %d",b,c);
	
	return 0;
}

