#include "bst.h"

BST::Node::Node(int value, Node* left, Node* right)
{
    this->left = left;
    this->right = right;
    this->value = value;
}