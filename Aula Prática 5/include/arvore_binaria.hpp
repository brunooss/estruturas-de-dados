#ifndef TREE_HPP
#define TREE_HPP

class Node {
public:
    double data;
    Node* left;
    Node* right;

    Node(double data);
    ~Node();
};

class ArvoreBinaria {
private:
    Node* root;

public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void insere(double data);
    Node* raiz();
    double* getPreOrdem();
    double* getInOrdem();
    double* getPosOrdem();

    void aleatoria(ArvoreBinaria& arvore);

    bool ancestral(double i, double j);

private:
    void insereRecursivamente(Node* curr, double data);
    void destroiRecursivamente(Node* curr);
    void preOrdemRecursivo(Node* curr, double* arr, int& index);
    void inOrdemRecursivo(Node* curr, double* arr, int& index);
    void posOrdemRecursivo(Node* curr, double* arr, int& index);
};

#endif
