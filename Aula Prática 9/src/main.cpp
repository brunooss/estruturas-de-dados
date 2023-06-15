#include <iostream>
#include "../include/AVL.hpp"

int main()
{
  AVLTree tree;

  // Inserção de elementos para teste
  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);
  tree.insert(10);
  tree.insert(25);
  tree.insert(35);
  tree.insert(45);
  tree.insert(55);
  tree.insert(65);
  tree.insert(75);
  tree.insert(90);
  tree.insert(91);
  tree.insert(89);
  tree.insert(72);
  tree.insert(84);
  tree.insert(85);
  tree.insert(86);
  tree.insert(82);
  tree.insert(83);
  tree.insert(81);
  tree.insert(87);
  tree.insert(86);

  // Imprime a árvore no formato de pré-ordem
  std::cout << "Preorder traversal: ";
  tree.printPreorder();
  std::cout << std::endl;

  // Imprime a árvore no formato de ordem
  std::cout << "Inorder traversal: ";
  tree.printInorder();
  std::cout << std::endl;

  // Imprime a representação gráfica da árvore
  std::cout << "Tree dump:" << std::endl;
  tree.dump();

  // Remoção de elementos para teste
  tree.remove(45);
  tree.remove(25);
  tree.remove(20);
  tree.remove(35);
  tree.remove(40);
  tree.remove(10);
  tree.remove(30);
  tree.remove(65);
  tree.remove(50);
  tree.remove(55);

  // Imprime a representação gráfica da árvore após remoção
  std::cout << "Tree dump after removal:" << std::endl;
  tree.dump();

  // Imprime a árvore após a remoção
  std::cout << "Preorder traversal after removal: ";
  tree.printPreorder();
  std::cout << std::endl;

  return 0;
}
