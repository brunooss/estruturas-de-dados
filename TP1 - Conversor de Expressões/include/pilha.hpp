#ifndef PILHA_HPP
#define PILHA_HPP

const int MAX_SIZE = 1000; // máximo de 1000 caracteres

class Pilha {
private:
    int topo; // índice do elemento do topo
    int arr[MAX_SIZE]; // array para armazenar elementos da pilha
public:
    Pilha();
    bool estaVazia();
    bool estaCheia();
    void empilha(int x);
    void desempilha();
    int topoDaPilha();
};

#endif
