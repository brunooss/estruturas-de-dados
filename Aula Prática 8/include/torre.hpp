#ifndef TORRE_HPP
#define TORRE_HPP

#include "./pilha.hpp"

class Torre
{
private:
  Pilha pilha;
  int n;

public:
  void adicionarDisco(int disco);
  int removerDisco();
  bool vazia() const;
  void moverDisco(int disco, Torre &origem, Torre &destino, Torre &auxiliar);
  void resolverTorreDeHanoi(int numDiscos, Torre &origem, Torre &destino, Torre &auxiliar);
  Torre(int id);
  int id;
  void inicializaTorreAleatoria(int n);
  void acessaTorre();
  void removeTorre();
  void imprimeTorre();
};

#endif // TORRE_HPP
