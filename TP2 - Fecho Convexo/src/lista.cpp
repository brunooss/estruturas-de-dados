#include "lista.hpp"
#include <iostream>

template<class T>
Lista<T>::Lista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

template<class T>
Lista<T>::~Lista() {
    Nodo* atual = inicio;
    while (atual != nullptr) {
        Nodo* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

template<class T>
int Lista<T>::getTamanho() const {
    return tamanho;
}

template<class T>
bool Lista<T>::estaVazia() const {
    return tamanho == 0;
}

template<class T>
void Lista<T>::adicionar(T& elemento) {
    Nodo* novoNodo = new Nodo(elemento);
    if (inicio == nullptr) {
        inicio = novoNodo;
        fim = novoNodo;
    } else {
        fim->proximo = novoNodo;
        fim = novoNodo;
    }
    tamanho++;
}

template<class T>
void Lista<T>::removerUltimo() {
    if (estaVazia()) {
        return;
    }

    if (inicio == fim) {
        delete fim;
        inicio = nullptr;
        fim = nullptr;
    } else {
        Nodo* atual = inicio;
        while (atual->proximo != fim) {
            atual = atual->proximo;
        }
        delete fim;
        atual->proximo = nullptr;
        fim = atual;
    }

    tamanho--;
}

template<class T>
T& Lista<T>::operator[](int indice) {
    Nodo* atual = inicio;
    int posicao = 0;
    while (atual != nullptr && posicao < indice) {
        atual = atual->proximo;
        posicao++;
    }
    return atual->elemento;
}