DIR_INC = ./yala
DIR_SRC = ./yala
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.cpp)
OBJ = $(patsubst %.cpp, ${DIR_OBJ}/%.o, $(notdir ${SRC}))

TARGET = yala

BIN_TARGET = $(DIR_BIN)/$(TARGET)

CC = g++
CFLAGS = -g -Wall -std=c++17 -I$(DIR_INC)

CPPFLAGS = -std=c++11

${BIN_TARGET}: ${OBJ} | ${DIR_BIN}
	${CC} ${OBJ} -o $@

${DIR_OBJ}/%.o: ${DIR_SRC}/%.cpp | ${DIR_OBJ}
	${CC} ${CFLAGS} -c $< -o $@

${DIR_BIN}:
	mkdir $@

${DIR_OBJ}:
	mkdir $@

.PHONY: clean
clean:
	rm -rf ${DIR_OBJ}/*.o
