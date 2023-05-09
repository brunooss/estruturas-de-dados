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

OBJS = $(OBJ)/pilha.o $(OBJ)/expressao.o $(OBJ)/main.o 
HDRS = $(INC)/pilha.hpp

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS)
	
$(OBJ)/expressao.o: $(HDRS) $(SRC)/expressao.cpp $(OBJ)/pilha.o
	$(CC) $(CFLAGS) -pg -c $(SRC)/expressao.cpp -o $(OBJ)/expressao.o

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp 
	$(CC) $(CFLAGS) -pg -c $(SRC)/pilha.cpp -o $(OBJ)/pilha.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -pg -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(EXE) $(OBJS) gmon.out