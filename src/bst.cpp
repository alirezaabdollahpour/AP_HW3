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
void BST::bfs(std::function<void(Node*& node)> func)
{
    std::queue<Node*> bfs_queue;
    if (root == nullptr)
        std::cout << "your BST is empty and bfs can't run!" << std::endl;
    bfs_queue.push(root);

    while (!bfs_queue.empty()) {
        Node* node = bfs_queue.front();
        bfs_queue.pop();
        if (node->left != nullptr)
            bfs_queue.push(node->left);
        if (node->right != nullptr)
            bfs_queue.push(node->right);

        func(node);
    }
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

BST::Node** BST::find_node(int value)
{
    BST::Node** finder { new BST::Node* };
    *finder = root;
    if (*finder == nullptr) {

        std::cout << "BST is empty" << std::endl;
        return nullptr;
    }
    while (1) {
        if (*finder = nullptr) {
            std::cout << "value doesn't exist" << std::endl;
            return nullptr;
        }
        if (*finder != nullptr && (*finder)->value > value)
            *finder = (*finder)->left;
        if (*finder != nullptr && (*finder)->value < value)
            *finder = (*finder)->right;
        if (*finder != nullptr && (*finder)->value == value)
            return finder;
    }
}

BST::Node** BST::find_parrent(int value)
{
    BST::Node** finder { new BST::Node* };
    *finder = root;
    if (*finder == nullptr)
        std::cout << "BST is empty" << std::endl;
    while (1) {
        if (*finder == nullptr) {
            std::cout << "BST doesn't have this value" << std::endl;
            return nullptr;
        }

        if (*finder != nullptr && (*finder)->value > value)
            if (*finder != nullptr && (*finder)->left->value == value)
                return finder;
            else
                *finder = (*finder)->left;
        if (*finder != nullptr && (*finder)->value < value)
            if (*finder != nullptr && (*finder)->right->value == value)
                return finder;
            else
                *finder = (*finder)->right;
    }
}

size_t BST::length()
{
    size_t count {};
    this->bfs([&](BST::Node*& node) { count++; });
    return count;
}
std::ostream& operator<<(std::ostream& os, BST& B)
{
    os << std::string(100, '*') << std::endl;
    size_t counter { 0 };
    B.bfs([&](BST::Node*& node) {
        counter++;
        os << *node;
    });
    os << "Binary Search tree size: " << counter << std::endl;
    os << std::string(100, '*') << std::endl;
    return os;
}

BST& BST::operator++()
{
    std::cout << "prefix ++ operator->++v" << std::endl;
    bfs([&](BST::Node*& node) { node->value++; });
    return *this;
}

BST BST::operator++(int)
{
    std::cout << "postfix ++ operator ->v++" << std::endl;
    // copy input BST to another bst
    BST bst { *this };
    ++(*this);
    return bst;
}

// BST::BST(BST& bst)
//     : root { nullptr }
// {
//     std::vector<int> values;
//     bst.bfs([&](BST::Node* node) { this->add_node(node->value); });
// }

// BST::~BST()
// {
//     std::vector<Node*> nodes;
//     bfs([&nodes](BST::Node*& node) { nodes.push_back(node); });
//     for (auto& node : nodes)
//         delete node;
// }