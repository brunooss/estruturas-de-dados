#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: compilar o programa 
# Autor			: Bruno Oliveira (bruno.oliveira@dcc.ufmg.br)
# Histórico	: 2023-05-01 - arquivo criado
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

OBJS = $(OBJ)/arvore_binaria.o $(OBJ)/main.o 
HDRS = $(INC)/arvore_binaria.hpp

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS)

$(OBJ)/arvore_binaria.o: $(HDRS) $(SRC)/arvore_binaria.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/arvore_binaria.cpp -o $(OBJ)/arvore_binaria.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(EXE) $(OBJS) gmon.out