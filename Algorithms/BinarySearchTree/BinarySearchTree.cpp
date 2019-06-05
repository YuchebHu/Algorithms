#include <iostream>

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
	};

	Node* root;
	int count;

public:
	BST() :root(NULL), count(0) {}

	~BST() {
		// TODO: ~BST()
	}

	bool isEmpty() {
		return count == 0;
	}

	int size() {
		return count;
	}

	void insert(Key key, Value value) {
		root = __insert(root, key, value);
	}

	bool contain(Key key) {
		return __contain(root, key);
	}

	Value* search(Key key) {
		return __search(root, key);
	}

private:
	Node* __insert(Node* node, Key key, Value value) {
		
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

	bool __contain(Node* node, Key key) {
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

	Value* __search(Node* node, Key key) {
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
};

int main() {
	return 0;
}