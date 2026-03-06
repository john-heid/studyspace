// studyspace.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

#include "Tree.h"

// Create dummy data


std::ostream& operator<<(std::ostream& out, std::vector<int>& data) {
    for (const auto& d : data) {
        out << d << " ";
    }
    return out;
}
std::ostream& operator<<(std::ostream& out, std::vector<std::vector<int>>& datas) {
    for (const auto& data : datas) {
        std::cout << std::endl;
        for (const auto& d : data) {
            out << d << " ";
        }
    }
    return out;
}


int main()
{
    std::vector<int> data{ 10, 20, 0, 15, 5, 12, 3, 6, 2, 9, 7, 17, 13, 12, 6, 16, 19 };
    Tree oak{};
    for (const auto& d : data) {
        oak.insert(d);
    }

    std::vector<int> inorder_data = oak.inorder();
    std::vector<int> preorder_data = oak.preorder();
    std::vector<std::vector<int>> levelorder_data = oak.levelorder();

    std::cout << "inorder:      " << inorder_data << std::endl;
    std::cout << "preorder:     " << preorder_data << std::endl;
    std::cout << "levelorder:   " << levelorder_data << std::endl;

    



}
