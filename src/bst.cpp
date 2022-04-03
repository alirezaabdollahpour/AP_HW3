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
    if (root == nullptr) {
        std::cout << "your BST is empty and bfs can't run!" << std::endl;
        return;
    }
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
    BST::Node* newNode { new BST::Node(value, nullptr, nullptr) };
    BST::Node* child { new BST::Node() };
    child = root;
    BST::Node* parent { new BST::Node() };
    if (root == nullptr) {
        root = newNode;
        return true;
    }
    while (child != nullptr) {
        parent = child;
        if (value > child->value) {
            child = child->right;
        } else if (value < child->value) {
            child = child->left;
        } else {
            return false;
        }
    }
    if (parent->left == nullptr && parent->value > value) {
        parent->left = newNode;
        return true;
    } else if (parent->right == nullptr && parent->value < value) {
        parent->right = newNode;
        return true;
    }
    return false;
}

BST::Node** BST::find_node(int value)
{
    if (root == nullptr) {
        return nullptr;
    }
    std::queue<Node**> finder;
    finder.push(&root);
    Node** node = finder.back();
    while (true) {
        if ((*node)->value == value)
            break;
        else if ((*node)->left != nullptr
            && value < (*node)->value) {
            finder.push(&((*node)->left));
            finder.pop();
            node = finder.back();
        } else if ((*node)->right != nullptr
            && value > (*node)->value) {
            finder.push(&((*node)->right));
            finder.pop();
            node = finder.back();
        } else {
            return nullptr;
        }
    }
    return node;
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

BST& BST::operator=(BST& bst)
{
    if (this == &bst)
        return *this;
    delete this->root;
    std::vector<int> finder;
    bst.bfs([&finder](BST::Node*& node) { finder.push_back(node->value); });
    for (auto i = (finder.begin()); i != finder.end(); ++i)
        this->add_node(*i);
    return *this;
}

BST& BST::operator=(BST&& bst)
{
    if (this == &bst)
        return *this;
    delete root;
    root = bst.root;
    bst.root = nullptr;
    return *this;
}

BST::BST(BST& bst)
    : root { nullptr }
{
    bst.bfs([&](BST::Node*& node) { this->add_node(node->value); });
}

BST::BST(BST&& bst)
{
    root = bst.get_root();
    bst.root = nullptr;
}

BST::~BST()
{
    std::vector<Node*> nodes;
    bfs([&nodes](BST::Node*& node) { nodes.push_back(node); });
    for (auto& node : nodes)
        delete node;
}

BST::Node** BST::find_successor(int value)
{
    BST::Node** finder { new BST::Node* };
    *finder = *this->find_node(value);
    if (*finder == nullptr)
        return nullptr;
    if ((*finder)->left == nullptr)
        return finder;
    else if ((*finder)->left->right == nullptr) {
        *finder = (*finder)->left;
        return finder;
    } else
        (*finder) = (*finder)->left;
    while ((*finder)->right != nullptr)
        (*finder) = (*finder)->right;

    return finder;
}

bool BST::delete_node(int value)
{
    if (this->find_node(value) == nullptr)
        return false;
    else {
        Node** node = this->find_node(value);
        if ((*node)->left == nullptr && (*node)->right == nullptr) {
            delete (*node);
            (*node) = nullptr;
            return true;
        } else if ((*node)->left == nullptr) {
            (*node) = (*node)->right;
            return true;
        } else if ((*node)->right == nullptr) {
            (*node) = (*node)->left;
            return true;
        } else {
            Node** finder = this->find_successor(value);
            (*node)->value = (*finder)->value;
            delete (*finder);
            (*finder) = nullptr;
        }
    }

    return true;
}