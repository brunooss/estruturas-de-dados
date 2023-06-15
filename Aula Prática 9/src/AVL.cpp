#include "../include/AVL.hpp"
#include <cmath>
#include <iostream>

Node::Node(int value) : data(value), left(nullptr), right(nullptr), height(1.0) {}

AVLTree::AVLTree() : root(nullptr) {}

void AVLTree::insert(int key)
{
  root = insertNode(root, key);
}

void AVLTree::remove(int key)
{
  root = removeNode(root, key);
}

void AVLTree::printPreorder()
{
  printPreorder(root);
  std::cout << std::endl;
}

void AVLTree::printInorder()
{
  printInorder(root);
  std::cout << std::endl;
}

void AVLTree::dump()
{
  dump(root, 0, "");
}

Node *AVLTree::insertNode(Node *node, int key)
{
  if (node == nullptr)
  {
    return new Node(key);
  }

  if (key < node->data)
  {
    node->left = insertNode(node->left, key);
  }
  else if (key > node->data)
  {
    node->right = insertNode(node->right, key);
  }

  node->height = updateHeight(node);

  double balanceFactor = getBalanceFactor(node);

  if (balanceFactor > std::sqrt(2))
  {
    if (key < node->left->data)
    {
      return rotateRight(node);
    }
    else
    {
      return rotateLeftRight(node);
    }
  }

  if (balanceFactor < -std::sqrt(2))
  {
    if (key > node->right->data)
    {
      return rotateLeft(node);
    }
    else
    {
      return rotateRightLeft(node);
    }
  }

  return node;
}

Node *AVLTree::removeNode(Node *node, int key)
{
  if (node == nullptr)
  {
    return nullptr;
  }

  if (key < node->data)
  {
    node->left = removeNode(node->left, key);
  }
  else if (key > node->data)
  {
    node->right = removeNode(node->right, key);
  }
  else
  {
    if (node->left == nullptr || node->right == nullptr)
    {
      Node *temp = node->left ? node->left : node->right;

      if (temp == nullptr)
      {
        temp = node;
        node = nullptr;
      }
      else
      {
        *node = *temp;
      }

      delete temp;
    }
    else
    {
      Node *temp = node->right;

      while (temp->left != nullptr)
      {
        temp = temp->left;
      }

      node->data = temp->data;
      node->right = removeNode(node->right, temp->data);
    }
  }

  if (node == nullptr)
  {
    return nullptr;
  }

  node->height = updateHeight(node);

  double balanceFactor = getBalanceFactor(node);

  if (balanceFactor > std::sqrt(2))
  {
    if (getBalanceFactor(node->left) >= 0)
    {
      return rotateRight(node);
    }
    else
    {
      return rotateLeftRight(node);
    }
  }

  if (balanceFactor < -std::sqrt(2))
  {
    if (getBalanceFactor(node->right) <= 0)
    {
      return rotateLeft(node);
    }
    else
    {
      return rotateRightLeft(node);
    }
  }

  return node;
}

double AVLTree::updateHeight(Node *node)
{
  double leftHeight = getHeight(node->left);
  double rightHeight = getHeight(node->right);

  return 1.0 + std::sqrt(leftHeight * leftHeight + rightHeight * rightHeight);
}

double AVLTree::getHeight(Node *node)
{
  return node ? node->height : 0.0;
}

double AVLTree::getBalanceFactor(Node *node)
{
  return getHeight(node->left) - getHeight(node->right);
}

Node *AVLTree::rotateLeft(Node *node)
{
  Node *newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;

  node->height = updateHeight(node);
  newRoot->height = updateHeight(newRoot);

  return newRoot;
}

Node *AVLTree::rotateRight(Node *node)
{
  Node *newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;

  node->height = updateHeight(node);
  newRoot->height = updateHeight(newRoot);

  return newRoot;
}

Node *AVLTree::rotateLeftRight(Node *node)
{
  node->left = rotateLeft(node->left);
  return rotateRight(node);
}

Node *AVLTree::rotateRightLeft(Node *node)
{
  node->right = rotateRight(node->right);
  return rotateLeft(node);
}

void AVLTree::printPreorder(Node *node)
{
  if (node != nullptr)
  {
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
  }
}

void AVLTree::printInorder(Node *node)
{
  if (node != nullptr)
  {
    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
  }
}

void AVLTree::dump(Node *node, int level, std::string prefix)
{
  if (node != nullptr)
  {
    dump(node->right, level + 1, prefix + "    ");
    for (int i = 0; i < level; i++)
      std::cout << prefix;
    std::cout << node->data << std::endl;
    dump(node->left, level + 1, prefix + "    ");
  }
}
