#include "bst.h"

BST::Node::Node(int value, Node* left, Node* right)
{
    this->left = left;
    this->right = right;
    this->value = value;
}

BST::Node::Node(const Node& node) // copy Node constructor
{
    value = node.value;
    right = node.right;
    left = node.left;
}
BST::Node*& BST::get_root()
{
    return root;
}