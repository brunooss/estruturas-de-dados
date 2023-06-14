#ifndef PILHA_HPP
#define PILHA_HPP

#include <stdexcept>

template <typename T>
class Pilha
{
private:
    struct No
    {
        T valor;
        No *proximo;

        No(const T &v, No *prox) : valor(v), proximo(prox) {}
    };

    No *topNode;

public:
    Pilha();
    ~Pilha();

    void empilha(const T &valor);
    void desempilha();
    T &topo();
    const T &topo() const;
    bool vazia() const;
    int tamanho() const;
};

#endif // PILHA_HPP
