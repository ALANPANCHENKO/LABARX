.PHONY: clean all

CC = gcc
FLAGS = -Wall -std=c99 -o 
SRC = main.c variables.c sc_memoryInit.c sc_memorySet.c sc_memoryGet.c sc_memorySave.c sc_memoryLoad.c sc_regInit.c sc_regSet.c sc_regGet.c sc_commandEncode.c compare.c sc_commandDecode.c
OBJ = $(SRC:.c=.o)

all: 
	$(CC) $(FLAGS) main $(SRC)
	
clean:
	rm -f *.o
