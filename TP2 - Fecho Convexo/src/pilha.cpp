#include "pilha.hpp"

template <typename T>
Pilha<T>::Pilha() : topNode(nullptr) {}

template <typename T>
Pilha<T>::~Pilha()
{
    while (!vazia())
    {
        desempilha();
    }
}

template <typename T>
void Pilha<T>::empilha(const T &valor)
{
    No *novoNo = new No(valor, topNode);
    topNode = novoNo;
}

template <typename T>
void Pilha<T>::desempilha()
{
    if (!vazia())
    {
        No *temp = topNode;
        topNode = topNode->proximo;
        delete temp;
    }
    else
    {
        throw std::runtime_error("Pilha vazia! Impossível desempilhar.");
    }
}

template <typename T>
T &Pilha<T>::topo()
{
    if (!vazia())
    {
        return topNode->valor;
    }
    else
    {
        throw std::runtime_error("Pilha vazia!");
    }
}

template <typename T>
const T &Pilha<T>::topo() const
{
    if (!vazia())
    {
        return topNode->valor;
    }
    else
    {
        throw std::runtime_error("Pilha vazia!");
    }
}

template <typename T>
bool Pilha<T>::vazia() const
{
    return topNode == nullptr;
}

template <typename T>
int Pilha<T>::tamanho() const
{
    int count = 0;
    No *temp = topNode;
    while (temp != nullptr)
    {
        temp = temp->proximo;
        count++;
    }
    return count;
}