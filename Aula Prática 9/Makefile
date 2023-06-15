#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: compilar o programa 
# Autor			: Bruno Oliveira (bruno.oliveira@dcc.ufmg.br)
# Histórico	: 2023-04-26 - arquivo criado
#---------------------------------------------------------------------
# Opções		: make all - compila tudo e executa exemplo
#						: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
CFLAGS = -Wall -I$(INC) -std=c++11

SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/AVL.o $(OBJ)/main.o 
HDRS = $(INC)/AVL.hpp

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS)

$(OBJ)/AVL.o: $(HDRS) $(SRC)/AVL.cpp 
	$(CC) $(CFLAGS) -pg -c $(SRC)/AVL.cpp -o $(OBJ)/AVL.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -pg -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(EXE) $(OBJS) gmon.out