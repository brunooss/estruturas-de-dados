#include "../include/item.hpp"

class Item {
public:

    enum class TipoOperador { Soma, Subtracao, Multiplicacao, Divisao, Numero }

    long double valor;
    TipoOperador operador;

    Item::isOperador() {
      return (this.operador != TipoOperador::Numero);
    }

    Item::isValue() {
      return (this.operador == TipoOperador::Numero);
    }

    Item(long double valor, TipoOperador operador);
    ~Item();
};

#endif /* ITEM_H */