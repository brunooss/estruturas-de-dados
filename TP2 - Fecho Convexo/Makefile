#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/convexo.o $(OBJ)/pilha.o $(OBJ)/lista.o $(OBJ)/ponto.o $(OBJ)/reta.o $(OBJ)/main.o 
HDRS = $(INC)/convexo.hpp $(INC)/pilha.hpp $(INC)/lista.hpp $(INC)/ponto.hpp $(INC)/reta.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) fecho pontos.txt

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/convexo.o: $(HDRS) $(SRC)/convexo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/convexo.o $(SRC)/convexo.cpp 
	
$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 
	
$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp 
	
$(OBJ)/ponto.o: $(HDRS) $(SRC)/ponto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ponto.o $(SRC)/ponto.cpp 

$(OBJ)/reta.o: $(HDRS) $(SRC)/reta.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/reta.o $(SRC)/reta.cpp 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
