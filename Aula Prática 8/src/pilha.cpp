#include "../include/pilha.hpp"
#include <iostream>

using namespace std;

Pilha::Pilha() : topo(nullptr) {}

Pilha::~Pilha()
{
  while (!vazia())
  {
    pop();
  }
}

void Pilha::push(int valor)
{
  Node *novoNo = new Node;
  novoNo->valor = valor;
  novoNo->proximo = topo;
  topo = novoNo;
}

int Pilha::pop()
{
  if (vazia())
  {
    std::cerr << "Erro: Pilha vazia!\n";
    return -1; // Valor de erro
  }

  Node *noRemovido = topo;
  int valor = noRemovido->valor;
  topo = topo->proximo;
  delete noRemovido;
  return valor;
}

bool Pilha::vazia() const
{
  return topo == nullptr;
}
