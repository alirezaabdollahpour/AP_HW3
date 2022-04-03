#include "bst.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        BST bst {};
        bst.add_node(25);
        bst.add_node(10);
        bst.add_node(50);
        bst.add_node(65);
        bst.add_node(60);
        bst.add_node(70);
        bst.add_node(5);
        bst.add_node(2);
        bst.add_node(7);
        bst.add_node(75);
        bst.add_node(20);
        bst.add_node(15);

        std::cout << "find successor:" << bst.find_successor(10) << std::endl;
        std::cout << "find successor:" << bst.find_successor(10) << std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}