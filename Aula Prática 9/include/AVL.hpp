#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cmath>
#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  double height;

  Node(int value);
};

class AVLTree
{
public:
  AVLTree();
  void insert(int key);
  void remove(int key);
  void printPreorder();
  void printInorder();
  void dump();

private:
  Node *root;

  Node *insertNode(Node *node, int key);
  Node *removeNode(Node *node, int key);
  double updateHeight(Node *node);
  double getHeight(Node *node);
  double getBalanceFactor(Node *node);
  Node *rotateLeft(Node *node);
  Node *rotateRight(Node *node);
  Node *rotateLeftRight(Node *node);
  Node *rotateRightLeft(Node *node);
  void printPreorder(Node *node);
  void printInorder(Node *node);
  void dump(Node *node, int level, string prefix);
};

#endif // AVL_TREE_H
