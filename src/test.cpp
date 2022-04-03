#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void print(int& value)
{
    std::cout << "value is" << value << std::endl;
}

void foreach (std::vector<int>& values, std::function<void(int&)> & func)
{
    for (int val : values)
        func(val);
}
int main()
{
    int a { 2 };
    int* p { &a };
    int** q { &p };
    int* arr { new int[5] };
    int** arr2 { new int*[5] };

    // BST::Node** temp { new BST::Node* };
    // *temp = *this->find_node(m_value);

    // std::cout << arr << std::endl;
    // std::cout << arr2 << std::endl;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << q << std::endl;
    std::cout << *q << std::endl;
    std::cout << **q << std::endl;
}