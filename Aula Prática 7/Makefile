CC = g++
LIBS = -lm
CFLAGS = -Wall -I$(INC) -std=c++11

SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/vector.o $(OBJ)/shellsort.o $(OBJ)/heapsort.o $(OBJ)/main.o

EXE = $(BIN)/sort_comparison

all: $(EXE)

$(BIN)/sort_comparison: $(OBJS)
	$(CC) -o $(BIN)/sort_comparison $(OBJS)

$(OBJ)/vector.o: $(INC)/vector.hpp $(SRC)/vector.cpp
	$(CC) $(CFLAGS) -c $(SRC)/vector.cpp -o $(OBJ)/vector.o

$(OBJ)/shellsort.o: $(INC)/shellsort.hpp $(SRC)/shellsort.cpp $(OBJ)/vector.o
	$(CC) $(CFLAGS) -c $(SRC)/shellsort.cpp -o $(OBJ)/shellsort.o

$(OBJ)/heapsort.o: $(INC)/heapsort.hpp $(SRC)/heapsort.cpp $(OBJ)/vector.o
	$(CC) $(CFLAGS) -c $(SRC)/heapsort.cpp -o $(OBJ)/heapsort.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/shellsort.hpp $(INC)/heapsort.hpp $(OBJ)/vector.o
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(EXE) $(OBJS)
