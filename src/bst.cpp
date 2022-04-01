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

bool BST::add_node(int value)
{
    if (get_root() == nullptr) {
        root = new Node;
        root->value = value;
        root->right = nullptr;
        root->left = nullptr;
        return 1;
    }
    BST::Node* pntr { root };
    while (1) {
        if (value > pntr->value) {
            if (pntr->right == nullptr) {
                pntr->right = new Node;
                pntr = pntr->right;

                pntr->value = value;
                std::cout << *(pntr) << std::endl;
                return 1;
            } else {
                pntr = pntr->right;
            }
        } else {
            if (value == pntr->value)
                return 0;
            if (pntr->left == nullptr) {
                pntr->left = new Node;
                pntr = pntr->left;

                pntr->value = value;
                std::cout << *(pntr) << std::endl;
                return 1;
            } else {
                pntr = pntr->left;
            }
        }
    }
}
