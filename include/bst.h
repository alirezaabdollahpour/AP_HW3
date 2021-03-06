#ifndef BST_H
#define BST_H

#include <compare>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class BST {
public:
    class Node {
    public:
        Node(int value, Node* left, Node* right);
        Node(); // default constructor
        Node(const Node& node); // copy constructor
        std::partial_ordering operator<=>(int _N) const { return this->value <=> _N; }
        bool operator==(int N) const { return this->value == N; }
        friend std::ostream& operator<<(std::ostream& os, const BST::Node& node)
        {
            os << "node address is:" << &node << "node left chiled value:" << node.left << "node right chiled value" << node.right;
            return os;
        }

        int value;
        Node* left;
        Node* right;
    };
    Node*& get_root();
    ~BST();
    BST(BST& bst);
    BST(BST&& bst);
    BST();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    friend std::ostream& operator<<(std::ostream& os, BST& B);
    BST& operator++();
    BST operator++(int);
    BST& operator=(BST& bst);
    BST& operator=(BST&& bst);
    BST(std::initializer_list<int> nodes);

private:
    Node* root;
};

#endif // BST_H