#pragma once
#include <vector>

struct Node {
	int m_val{};
	int counter{};
	Node* left{ nullptr };
	Node* right{ nullptr };
	Node(int val) : m_val{ val } {};
};

class Tree
{
public:
	void insert(int);
	std::vector<int> inorder() const; // inorder traversals terminate in an ascending order
	void printTree() const; // level order traversal / breadth first search style
	// get degree get level etc
	// Print Tree
		// Probably use the depth of the tree to determine spacing visually
private:
	// Member Variables
	Node* m_root{ nullptr };

	// Member Functions
	void helper_inorder(Node* curr, std::vector<int>& result) const;
};

