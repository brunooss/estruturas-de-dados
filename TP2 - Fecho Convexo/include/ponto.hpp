#ifndef PONTO_HPP
#define PONTO_HPP

class Ponto {
private:
    int x;
    int y;

public:
    Ponto(int x, int y);
    int getX() const;
    int getY() const;
    double calcularDistancia(const Ponto& outroPonto) const;
};

#endif