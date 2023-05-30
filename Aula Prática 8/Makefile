#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#               : 2021-11-15 - Versao 1.1 memlog
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pilha.o $(OBJ)/torre.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/pilha.hpp $(INC)/torre.hpp $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/main

all-cria:  mem-cria perf-cria gprof-cria
mem-cria: $(EXE)
	$(EXE) -c -p ./crialog.out
perf-cria: $(EXE)
	$(EXE) -c -p ./crialog10.out
gprof-cria: $(BIN)/main
	$(EXE) -c -p ./crialog15.out
	gprof $(EXE) gmon.out > ./crialog15.txt


all-ordena:  mem-ordena perf-ordena gprof-ordena
mem-ordena: $(EXE)
	$(EXE) -o -p ./ordenalog.out
perf-ordena: $(EXE)
	$(EXE) -o -p ./ordenalog10.out
gprof-ordena: $(BIN)/main
	$(EXE) -o -p ./ordenalog.out
	gprof $(EXE) gmon.out > ./ordenalog15.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS)

$(OBJ)/torre.o: $(HDRS) $(SRC)/torre.cpp $(OBJ)/pilha.o
	$(CC) $(CFLAGS) -pg -c $(SRC)/torre.cpp -o $(OBJ)/torre.o

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp 
	$(CC) $(CFLAGS) -pg -c $(SRC)/pilha.cpp -o $(OBJ)/pilha.o

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -pg -c $(SRC)/main.cpp -o $(OBJ)/main.o
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*
