BUILD_DIRS=bin obj
CC = gcc
FLAGS = -Wall
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/app
LIB = $(OBJ_DIR)/libmySimpleComputer.a

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
$(BIN_DIR):
	mkdir $(BIN_DIR)
	
.PHONY: clean

all: $(TARGET)
	
$(LIB): $(OBJ)
	ar rvs $@ $^
	
$(TARGET): $(OBJ_DIR)/main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L -lmySimpleComputer

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*main
	rm -f $(OBJ_DIR)/*.a	
