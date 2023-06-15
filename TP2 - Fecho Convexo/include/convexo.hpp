#ifndef CONVEXO_H
#define CONVEXO_H

#include "lista.hpp"
#include "ponto.hpp"
#include "pilha.hpp"

#include <iostream>

class FechoConvexo {
private:
    Lista<Ponto> pontos;

public:
    FechoConvexo(Lista<Ponto>& pontos);
    ~FechoConvexo();

    Lista<Ponto> calcularFechoConvexoJarvis();
    Lista<Ponto> calcularFechoConvexoGraham(std::string);

    void ordenarPolar(Ponto pontoReferencia, std::string ordenacao);
    Ponto anteriorAoTopo(Pilha<Ponto>& pilha);
    int posicaoMenorY();
    

private:
    int orientacao(Ponto p, Ponto q, Ponto r);
    bool pontoNoSegmento(const Ponto& p, const Ponto& q, const Ponto& r) const;

    int getMaximo(Ponto pontoReferencia);
    void mergesort(Ponto pontoReferencia, int esquerda, int direita);
    void merge(Ponto pontoReferencia, int esquerda, int meio, int direita);
    void insertionsort(Ponto pontoReferencia);
    void bubblesort(Ponto pontoReferencia);
    void countingSort(Ponto pontoReferencia, int tamanho, int exp);

};

#endif