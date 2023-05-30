#include <iostream>
#include "../include/torre.hpp"
#include "memlog.h"
#include "msgassert.h"

// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10

using namespace std;

Torre::Torre(int id)
{
    this->id = id;
}

void Torre::adicionarDisco(int disco)
{
    pilha.push(disco);
    ESCREVEMEMLOG((long int)(&(disco)), sizeof(double), this->id);
}

int Torre::removerDisco()
{
    int valor = pilha.topo->valor;
    pilha.pop();
    LEMEMLOG((long int)(&(valor)), sizeof(int), this->id);
    return valor;
}

bool Torre::vazia() const
{
    return pilha.vazia();
}

void Torre::inicializaTorreAleatoria(int n)
{
    for (int i = 0; i < n; i++)
    {
        int valor = drand48() * INITRANDOMRANGE;
        adicionarDisco(valor);
        ESCREVEMEMLOG((long int)(&(valor)), sizeof(int), this->id);
    }
}

void Torre::moverDisco(int disco, Torre &origem, Torre &destino, Torre &auxiliar)
{
    if (disco == 1)
    {
        int valor = origem.removerDisco();
        destino.adicionarDisco(valor);
        std::cout << "Mover disco " << valor << " de Origem para Destino\n";
        ESCREVEMEMLOG((long int)(&(valor)), sizeof(int), this->id);
    }
    else
    {
        moverDisco(disco - 1, origem, auxiliar, destino);
        int valor = origem.removerDisco();
        destino.adicionarDisco(valor);
        std::cout << "Mover disco " << valor << " de Origem para Destino\n";
        ESCREVEMEMLOG((long int)(&(valor)), sizeof(int), this->id);
        moverDisco(disco - 1, auxiliar, destino, origem);
    }
}

void Torre::resolverTorreDeHanoi(int numDiscos, Torre &origem, Torre &destino, Torre &auxiliar)
{

    // Preencher a torre de origem com os discos em ordem decrescente
    for (int i = numDiscos; i >= 1; --i)
    {
        origem.adicionarDisco(i);
    }

    this->moverDisco(numDiscos, origem, destino, auxiliar);
}

void Torre::acessaTorre()
{
    Pilha::Node *atual = pilha.topo;
    while (atual != nullptr)
    {
        // Realizar a operação desejada em cada elemento da torre
        // Por exemplo, imprimir o valor do disco
        LEMEMLOG((long int)(&(atual->valor)), sizeof(double), this->id);

        // Avançar para o próximo nó
        atual = atual->proximo;
    }
}

void Torre::removeTorre()
{
    while (pilha.topo != nullptr)
    {
        Pilha::Node *nodoRemovido = pilha.topo;
        pilha.pop();

        avisoAssert((pilha.topo == nullptr), "A torre já foi destruida");
        if (pilha.topo != nullptr)
            delete nodoRemovido;
    }
}

void Torre::imprimeTorre()
{
    Pilha::Node *atual = pilha.topo;
    while (atual != nullptr)
    {
        std::cout << atual->valor << " ";
        LEMEMLOG((long int)(&(atual->valor)), sizeof(double), this->id);
        atual = atual->proximo;
    }
    std::cout << std::endl;
}
