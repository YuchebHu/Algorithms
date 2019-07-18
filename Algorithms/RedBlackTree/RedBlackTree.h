#pragma once

#include <iostream>
#include <cassert>
#include <queue>

const static bool RED = true;
const static bool BLACK = false;

template <typename Key, typename Value>
class RedBlackTree {
private:
	struct Node {
		Key key;
		Value value;
		bool color;
		Node* left;
		Node* right;

		Node(Key key, Value value, bool color) {
			this->key = key;
			this->value = value;
			this->color = color;
			this->left = this->right = NULL;
		}

		Node(Node node) {
			this->key = node.key;
			this->value = node.key;
			this->color = node.color;
			this->left = node.left;
			this->right = node.right;
		}
	};

	Node* root;
	int count;
	int height;

	bool isRed(Node* node) {
		if (node == NULL) {
			return false;
		}
		return node->color == RED;
	}

public:
	RedBlackTree() : root(NULL), count(0), height(0) {

	}

	~RedBlackTree() {
		destory();
	}

	void preOrder() {
		__preOrder(root);
	}

	void inOrder() {
		__inOrder(root);
	}

	void postOrder() {
		__postOrder(root);
	}

	void destory() {
		__destory(root);
	}

	int size() {
		return count;
	}

	Node* rotateLeft(Node* node) {
		Node* x(node->right);
		node->right = x->left;
		x->left = node;
		x->color = node->color;
		node->color = RED;
		return x;
	}

	Node* rotateRight(Node* node) {
		Node* x(node->left);
		node->left = x->right;
		x->right = node;
		x->color = node->color;
		node->color = RED;
		return x;
	}
private:
	int __size(Node* node) {
		int size = 0;
		if (node != NULL) {
			size += __size(node->left);
			size += __size(node->right);
		}

		return size;
	}

	void __preOrder(Node* node) {
		if (node != null) {
			std::cout << node->value << std::endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}
	}

	void __inOrder(Node* node) {
		if (node != NULL) {
			__inOrder(node->left);
			std::cout << node->value << std::endl;
			__inOrder(node->right);
		}
	}

	void __postOrder(Node* node) {
		if (node != NULL) {
			__postOrder(node->left);
			__postOrder(node->right);
			std::cout << node->value << std::endl;
		}
	}

	void __destory(Node* node) {
		if (node != NULL) {
			__destory(node->left);
			__destory(node->right);
			delete node;
			--count;
		}
	}


};