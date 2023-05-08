#include "pilha.hpp"
#include <iostream>
using namespace std;

Pilha::Pilha() {
    topo = -1; // a pilha está inicialmente vazia
}

bool Pilha::estaVazia() {
    return topo == -1;
}

bool Pilha::estaCheia() {
    return topo == MAX_SIZE - 1;
}

void Pilha::empilha(int x) {
    if (estaCheia()) {
        cout << "Erro: estouro de pilha\n";
        return;
    }
    arr[++topo] = x;
}

void Pilha::desempilha() {
    if (estaVazia()) {
        cout << "Erro: subfluxo de pilha\n";
        return;
    }
    topo--;
}

int Pilha::topoDaPilha() {
    if (estaVazia()) {
        cout << "Erro: a pilha está vazia\n";
        return -1;
    }
    return arr[topo];
}
