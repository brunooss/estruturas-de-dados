#include <iostream>

#include "../include/arvore_binaria.hpp"

Node::Node(double data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    // delete left;
    // delete right;
}

ArvoreBinaria::ArvoreBinaria() {
    root = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    destroiRecursivamente(root);
}

void ArvoreBinaria::insere(double data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        insereRecursivamente(root, data);
    }
}

Node* ArvoreBinaria::raiz() {
    return root;
}

double* ArvoreBinaria::getPreOrdem() {
    double* arr = new double[10];
    int index = 0;
    preOrdemRecursivo(root, arr, index);

    return arr;
}

double* ArvoreBinaria::getInOrdem() {
    double* arr = new double[10];
    int index = 0;
    inOrdemRecursivo(root, arr, index);

    return arr;
}

double* ArvoreBinaria::getPosOrdem() {
    double* arr = new double[10];
    int index = 0;
    posOrdemRecursivo(root, arr, index);

    return arr;
}

void ArvoreBinaria::insereRecursivamente(Node* curr, double data) {
    if (data < curr->data) {
        if (curr->left == nullptr) {
            curr->left = new Node(data);
        } else {
            insereRecursivamente(curr->left, data);
        }
    } else {
        if (curr->right == nullptr) {
            curr->right = new Node(data);
        } else {
            insereRecursivamente(curr->right, data);
        }
    }
}

void ArvoreBinaria::destroiRecursivamente(Node* curr) {
    if (curr != nullptr) {
        destroiRecursivamente(curr->left);
        destroiRecursivamente(curr->right);
        delete curr;
    }
}

void ArvoreBinaria::preOrdemRecursivo(Node* curr, double* arr, int& index) {
    if (curr != nullptr) {
        // std::cout << curr->data << " "; // Em vez de imprimir, salva no array

        arr[index] = curr->data;
        index++;

        preOrdemRecursivo(curr->left, arr, index);
        preOrdemRecursivo(curr->right, arr, index);
    }
}

void ArvoreBinaria::inOrdemRecursivo(Node* curr, double* arr, int& index) {
    if (curr != nullptr) {
        inOrdemRecursivo(curr->left, arr, index);
        // std::cout << curr->data << " "; // Em vez de imprimir, salva no array

        arr[index] = curr->data;
        index++;

        inOrdemRecursivo(curr->right, arr, index);
    }
}

void ArvoreBinaria::posOrdemRecursivo(Node* curr, double* arr, int& index) {
    if (curr != nullptr) {
        posOrdemRecursivo(curr->left, arr, index);
        posOrdemRecursivo(curr->right, arr, index);

        // std::cout << curr->data << " "; // Em vez de imprimir, salva no array
        arr[index] = curr->data;
        index++;
    }
}

void ArvoreBinaria::aleatoria(ArvoreBinaria& arvore) {
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        double value = (rand() % 1000) / 3.14159;
        arvore.insere(value);
    }
}

bool ArvoreBinaria::ancestral(double i, double j) {
  double* pos = getPosOrdem();

  int posicaoIPre = i, posicaoJPre = j;
  int posicaoIPos = 0, posicaoJPos = 0;

  for (int k = 0; k < 10; k++) {
    if (pos[k] == i) posicaoIPos = k;
    if (pos[k] == j) posicaoJPos = k;
  }

  return (posicaoIPre < posicaoJPre && posicaoIPos > posicaoJPos);
}