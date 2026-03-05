// studyspace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

#include "Tree.h"

// Tree Class
    // Holds a root*
    // Insertion
    // Deletion
    // Traversal
    // Search
// The 
    







int main()
{
    std::vector<int> data{ 10, 20, 0, 15, 5, 12, 3, 6, 2, 9, 7, 17, 13, 12, 6, 16, 19 };
    Tree oak{};
    for (const auto& d : data) {
        oak.insert(d);
    }

    std::vector<int> inorder_data{ oak.inorder() };

    for (const auto& d : inorder_data) {
        std::cout << d << " ";
    }

}
