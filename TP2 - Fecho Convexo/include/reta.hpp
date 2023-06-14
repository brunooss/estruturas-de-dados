#ifndef RETA_HPP
#define RETA_HPP

#include "./ponto.hpp"

class Reta {
private:
    Ponto ponto1;
    Ponto ponto2;

public:
    Reta(const Ponto& ponto1, const Ponto& ponto2);
    const Ponto& getPonto1() const;
    const Ponto& getPonto2() const;
};

#endif