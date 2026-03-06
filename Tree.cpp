#include "Tree.h"

#include <queue>
#include <iostream>

void Tree::insert(int val) {
	Node* newNode = new Node(val);
	if (!m_root) {
		m_root = newNode;
		return;
	}

	Node* curr = m_root;
	while (true) {
		if (newNode->m_val < curr->m_val) {
			if (!curr->left) {
				curr->left = newNode;
				return;
			}
			curr = curr->left;
		}

		else if (newNode->m_val > curr->m_val) {
			if (!curr->right) {
				curr->right = newNode;
				return;
			}
			curr = curr->right;
		}

		else {
			++curr->counter;
			return;
		}
	}
}

std::vector<int> Tree::inorder() const {
	Node* node{ m_root };
	std::vector<int> result{};
	helper_inorder(node, result);
	return result;
	

}
void Tree::helper_inorder(Node* curr, std::vector<int>& result) const {
	if (curr->left) {
		helper_inorder(curr->left, result);
	}
	result.push_back(curr->m_val);
	if (curr->right) {
		helper_inorder(curr->right, result);
	}
}

void Tree::printTree() const {
	Node* curr = m_root;
	std::vector<std::vector<Node*>> levels{};
	std::queue<Node*> q{};
	q.push(m_root);
	while (!q.empty()) {
		int level_size = q.size();
		std::vector<Node*> current_level{};

		for (int i{ 0 }; i < level_size; ++i) {
			Node* curr = q.front();
			q.pop();
			current_level.push_back(curr);

			if (curr != nullptr) {
				q.push(curr->left);
				q.push(curr->right);
			}
		}
		levels.push_back(current_level);
	}
	int padding_size = levels.size();
	std::cout << padding_size;
	for (const auto& level : levels) {
		for (const auto& node : level) {
			if (node) { 
				std::cout << node->m_val << " ";
			}
			else { 
				std::cout << "null ";
			}
		}
		std::cout << std::endl;
	}

	// I need a
	// Then a's children
	//	 a
	//	b c
	// de fg


}
