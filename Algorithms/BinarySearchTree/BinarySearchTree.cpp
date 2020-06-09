#pragma once

#include <cassert>
#include <iostream>
#include <queue>

template <typename Key, typename Value>
class BST {
private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		Node(Node* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node* root;
	int count;

public:
	BST()
		: root(NULL)
		, count(0) {
	}

	~BST() { destory(); }

	bool isEmpty() { return count == 0; }

	int size() { return count; }

	void insert(Key key, Value value) { root = __insert(root, key, value); }

	bool contain(Key key) { return __contain(root, key); }

	Value* search(Key key) { return __search(root, key); }

	void preOrder() { __preOrder(root); }

	void inOrder() { __inOrder(root); }

	void postOrder() { __postOrder(root); }

	void destory() { __destory(root); }

	void levelOrder() {
		std::queue<Node*> queue;
		queue.push(root);

		while (!queue.empty()) {
			Node* tempNode = queue.front();
			queue.pop();

			std::cout << tempNode->key << ": " << tempNode->value << std::endl;

			if (tempNode->left != NULL)
				queue.push(tempNode->left);
			if (tempNode->right != NULL)
				queue.push(tempNode->right);
		}
	}

	Key minimum() {
		assert(count != 0);
		Node * minNode = __minimum(root);
		return minNode->key;
	}

	Key maximum() {
		assert(count != 0);
		Node * maxNode = __maximum(root);
		return maxNode->key;
	}

	void removeMin() {
		if (root != NULL)
			root = __removeMin(root);
	}

	void removeMax() {
		if (root != NULL)
			root = __removeMax(root);
	}

	void remove(Key key) {
		root = __remove(root, key);
	}

private:
	Node* __insert(Node * node, Key key, Value value) {
		if (node == NULL) {
			++count;
			return new Node(key, value);
		}

		if (node->key == key) {
			node->value = value;
		}
		else if (node->key > key) {
			node->left = __insert(node->left, key, value);
		}
		else
			node->right = __insert(node->right, key, value);
		return node;
	}

	bool __contain(Node * node, Key key) {
		if (node == NULL) {
			return false;
		}

		if (node->key == key)
			return true;
		else if (node->key > key)
			return __contain(node->left, key);
		else
			return __contain(node->right, key);
	}

	Value* __search(Node * node, Key key) {
		if (node == NULL) {
			return NULL;
		}

		if (node->key == key)
			return &node->value;
		else if (node->key > key)
			return __search(node->left, key);
		else
			return __search(node->right, key);
	}

	void __preOrder(Node * node) {
		if (node != NULL) {
			std::cout << node->key << std::endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}
	}

	void __inOrder(Node * node) {
		if (node != NULL) {
			__inOrder(node->left);
			std::cout << node->key << std::endl;
			__inOrder(node->right);
		}
	}

	void __postOrder(Node * node) {
		if (node != NULL) {
			__postOrder(node->left);
			__postOrder(node->right);
			std::cout << node->key << std::endl;
		}
	}

	void __destory(Node * node) {
		if (node != NULL) {
			__destory(node->left);
			__destory(node->right);

			delete node;
			--count;
		}
	}

	Node* __minimum(Node * node) {
		if (node->left == NULL)
			return node;

		return __minimum(node->left);
	}

	Node* __maximum(Node * node) {
		if (node->right == NULL)
			return node;

		return __maximum(node->right);
	}

	Node* __removeMin(Node * node) {
		if (node->left == NULL) {
			Node* rightNode = node->right;
			delete node;
			--count;
			return rightNode;
		}

		node->left = __removeMin(node->left);
		return node;
	}

	Node* __removeMax(Node * node) {
		if (node->right == NULL) {
			Node* leftNode = node->left;
			delete node;
			--count;
			return leftNode;
		}

		node->right = __removeMax(node->right);
		return node;
	}

	Node* __remove(Node * node, Key key) {
		if (node == NULL) {
			return NULL;
		}

		if (key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else {
			if (node->left == NULL) {
				Node* rightNode = node->right;
				delete node;
				--count;
				return rightNode;
			}
			else if (node->right == NULL) {
				Node* leftNode = node->left;
				delete node;
				--count;
				return leftNode;
			}
			else {
				Node* successor(__minimum(node->right));
				++count;

				successor->right = __removeMin(node->right);
				successor->left = node->left;

				delete node;
				--count;

				return successor;
			}
		}
	}
};

int main() {
	BST<char, int> tree;

	return 0;
}