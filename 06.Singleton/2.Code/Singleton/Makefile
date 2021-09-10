DIR_INC = ./
DIR_SRC = ./
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.cpp)
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))

TARGET = main

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = g++
CFLAGS = -g -Wall -I${DIR_INC} -pthread


${BIN_TARGET}:${OBJ}
	mkdir -p $(DIR_BIN)
	$(CC) $(CFLAGS) $(OBJ) -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
    
clean:
	rm -rf bin obj
	rm -rf ./main