#ifndef PILHA_HPP
#define PILHA_HPP

class Pilha
{
private:
public:
  struct Node
  {
    int valor;
    Node *proximo;
  };

  Pilha();
  ~Pilha();

  Node *topo;

  void push(int valor);
  int pop();
  bool vazia() const;
};

#endif // PILHA_HPP
