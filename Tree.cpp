#include "Tree.h"

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

