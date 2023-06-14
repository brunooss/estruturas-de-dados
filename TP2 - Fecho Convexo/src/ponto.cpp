#include "ponto.hpp"

#include <iostream>
#include <cmath>

Ponto::Ponto(int x, int y) : x(x), y(y) {}

int Ponto::getX() const {
    return x;
}

int Ponto::getY() const {
    return y;
}

double Ponto::calcularDistancia(const Ponto& outroPonto) const {
    int deltaX = outroPonto.getX() - x;
    int deltaY = outroPonto.getY() - y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}