#ifndef _GUARD_H_
#define _GUARD_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

#define BIT_SET(A,B) (A = ((A) | (1 << (B-1))))
#define BIT_UNSET(A,B) (A = ((A) & ~(1 << (B-1))))
#define BIT_GET(A,B) (((A >> (B-1))& 0x1))

extern int Memory[SIZE];
extern int reg_flags;
extern const int cmd_num;
extern const int cmd_arr[];  
extern int flag;

int sc_memoryInit();
int sc_memorySet(int address,int value);
int sc_memoryGet(int address,int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit();
int sc_regSet(int reg,int value);
int sc_regGet(int reg,int *value);
int compare(const void *a,const void *b);
int sc_commandEncode(int command,int operand,int *value);
int sc_commandDecode(int value,int *command,int *operand);



#endif
