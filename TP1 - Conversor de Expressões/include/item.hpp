#ifndef ITEM_H
#define ITEM_H

class Item {
public:

    enum class TipoOperador { Soma, Subtracao, Multiplicacao, Divisao, Numero }

    long double valor;
    TipoOperador operador;

    bool isOperador();
    bool isValue();

    Item(long double valor, TipoOperador operador);
    ~Item();
};

#endif /* ITEM_H */