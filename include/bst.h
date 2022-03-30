#ifndef BST_H
#define BST_H

#include <compare>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class BST {
public:
    class Node {
    public:
        Node(int value, Node* left, Node* right);
        Node() = default; // default constructor
        Node(const Node& node); // copy constructor
        std::partial_ordering operator<=>(int _N) const { return value <=> _N; }
        bool operator==(int N) const { return value == N; }
        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {
            os << "node address is:" << &node << "node left chiled value:" << node.left << "node right chiled value" << node.right << std::endl;
            return os;
        }

        int value;
        Node* left;
        Node* right;
    };
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

private:
    Node* root;
};

#endif // BST_H