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
	if (curr->left) { helper_inorder(curr->left, result); }
	result.push_back(curr->m_val);
	if (curr->right) { helper_inorder(curr->right, result); }
}

std::vector<int> Tree::preorder() const {
	Node* node{ m_root };
	std::vector<int> result{};
	helper_preorder(node, result);
	return result;
}
void Tree::helper_preorder(Node* curr, std::vector<int>& result) const {
	result.push_back(curr->m_val);
	if (curr->left) { helper_preorder(curr->left, result); }
	if (curr->right) { helper_preorder(curr->right, result); }
}

std::vector<std::vector<int>> Tree::levelorder() const {
	if (m_root == nullptr) {
		return {};
	}
	std::queue<Node*> q{};
	std::vector<std::vector<int>> result{};

	q.push(m_root);
	int current_level{ 0 };

	while (!q.empty()) {
		int len = q.size();
		result.push_back({});

		for (int i{ 0 }; i < len; ++i) {
			Node* node = q.front();
			q.pop();

			result[current_level].push_back(node->m_val);

			if (node->left != nullptr) {
				q.push(node->left);
			}
			if (node->right != nullptr) {
				q.push(node->right);
			}
		}
		++current_level;
	}
	return result;
}
