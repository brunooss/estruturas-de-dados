#include "reta.hpp"

Reta::Reta(const Ponto& ponto1, const Ponto& ponto2) : ponto1(ponto1), ponto2(ponto2) {}

const Ponto& Reta::getPonto1() const {
    return ponto1;
}

const Ponto& Reta::getPonto2() const {
    return ponto2;
}