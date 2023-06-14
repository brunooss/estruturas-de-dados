#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstddef>

template<class T>
class Lista {
private:
    struct Nodo {
        T elemento;
        Nodo* proximo;

        Nodo(const T& elemento, Nodo* proximo = nullptr) : elemento(elemento), proximo(proximo) {}
    };

    Nodo* inicio;
    Nodo* fim;
    int tamanho;

public:
    Lista();
    ~Lista();

    int getTamanho() const;
    bool estaVazia() const;
    void adicionar(T& elemento);
    void removerUltimo();
    T& operator[](int indice);
};

#endif