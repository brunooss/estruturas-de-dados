#ifndef ITEM_H
#define ITEM_H

class Item {
public:

    enum class TipoOperador { Soma, Subtracao, Multiplicacao, Divisao, Numero }

    double valor;
    TipoOperador operador;

    bool isOperador();
    bool isValue();

    Item(double valor, TipoOperador operador);
    ~Item();
};

#endif /* ITEM_H */