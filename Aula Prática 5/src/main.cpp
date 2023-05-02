#include <iostream>

#include "../include/arvore_binaria.hpp"

int main() {

    ArvoreBinaria arvore;

    ArvoreBinaria().aleatoria(arvore);

    // Exibe as travessias pré-ordem, em ordem e pós-ordem
    std::cout << "Caminhamento Pré-ordem: ";
    double* pre = arvore.getPreOrdem();
    for (int i = 0; i < 10; i++) {
      std::cout << pre[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Caminhamento In-ordem: ";
    double* in = arvore.getInOrdem();
    for (int i = 0; i < 10; i++) {
      std::cout << in[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Caminhamento Pós-ordem: ";
    double* pos = arvore.getPosOrdem();
    for (int i = 0; i < 10; i++) {
      std::cout << pos[i] << " ";
    }
    std::cout << std::endl;

    for (int k = 0; k < 10; k++) {
      double i = pre[rand() % 10];
      double j = pre[rand() % 10];
      // std::cout.precision(5);
      std::cout << i << " " << (arvore.ancestral(i, j)? "e ": "nao e ") << "" << "ancestral de " << j << std::endl;
    }

    return 0;
}