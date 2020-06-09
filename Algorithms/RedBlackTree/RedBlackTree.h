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

		Node(Node* node) {
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

	void flipColors(Node* node) {
		node->color = RED;
		node->left->color = BLACK;
		node->right->color = BLACK;
	}

public:
	RedBlackTree() : root(NULL), count(0), height(0) {
		
	}

	~RedBlackTree() {
		destory();
	}

	void insert(Key key, Value value) {
		root = __insert(root, key, value);
		root->color = BLACK;
	}

	bool contain(Key key) {
		__contain(root, key);
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

	int Height() {
		return __Height(root);
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
		if (node != NULL) {
			std::cout << node->value << std::endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}
	}

	void __inOrder(Node* node) {
		if (node != NULL) {
			__inOrder(node->left);
			__inOrder(node->right);
			std::cout << node->value << std::endl;
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

	Node* __insert(Node* node, Key key, Value value) {
		if (node == NULL) {
			++count;
			return new Node(key, value, RED);
		}

		if (node->key > key)
			node->left = __insert(node->left, key, value);
		else if (node->key < key)
			node->right = __insert(node->right, key, value);
		else // node->key == key
			node->value = value;

		if (isRed(node->right) && !isRed(node->left)) // 右节点是红色
			node = rotateLeft(node);
		if (isRed(node->left) && isRed(node->left->left)) // 两个连续的左节点是红色
			node = rotateRight(node);
		if (isRed(node->left) && isRed(node->right)) // 左右两个节点都是红色
			flipColors(node);
		//std::cout << key << std::endl;
		return node;
	}

	bool __contain(Node* node, Key key) {
		if (node == NULL)
			return false;
		if (node->key == key)
			return true;
		else if (node->key > key)
			return __contain(node->left, key);
		else
			return __contain(node->right, key);
	}

	int __Height(Node* node) {
		int heightCount = 0;
		int heightLeft = 0;
		int heightRight = 0;
		if (node == NULL) {
			heightCount = 0;
			return heightCount;
		}

		heightLeft = __Height(node->left);
		heightRight = __Height(node->right);
		heightCount = 1 + ((heightLeft > heightRight) ? heightLeft : heightRight);
		return heightCount;
	}
};

