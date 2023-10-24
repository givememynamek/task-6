#include <iostream>
#include <memory>
using namespace std;
class Node {
public:
  int data;
  unique_ptr<Node> left;
  unique_ptr<Node> right;

  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
private:
  unique_ptr<Node> root;

public:
  BinaryTree() { root = nullptr; }

  void insert(int value) {
    if (root == nullptr) {
      root = make_unique<Node>(value);
      return;
    }

    Node *currentNode = root.get();
    while (true) {
      if (value < currentNode->data) {
        if (currentNode->left == nullptr) {
          currentNode->left = make_unique<Node>(value);
          return;
        }
        currentNode = currentNode->left.get();
      } else {
        if (currentNode->right == nullptr) {
          currentNode->right = make_unique<Node>(value);
          return;
        }
        currentNode = currentNode->right.get();
      }
    }
  }
};
