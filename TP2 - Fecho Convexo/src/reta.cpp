#include "reta.hpp"
#include <iostream>

Reta::Reta(const Ponto& ponto1, const Ponto& ponto2) : ponto1(ponto1), ponto2(ponto2) {}

const Ponto& Reta::getPonto1() const {
    return ponto1;
}

const Ponto& Reta::getPonto2() const {
    return ponto2;
}

void Reta::equacaoReta() const {
        double coeficienteAngular = (ponto2.getY() - ponto1.getY()) / (ponto2.getX() - ponto1.getX());
        double coeficienteLinear = ponto1.getY() - (coeficienteAngular * ponto1.getX());

        // std::cout << "A equação da reta que passa pelos pontos (" << ponto1.getX() << ", " << ponto1.getY() << ") e (" << ponto2.getX() << ", " << ponto2.getY() << ") é:" << std::endl;
        std::cout << "y = " << coeficienteAngular << "x + " << coeficienteLinear << std::endl;
    }