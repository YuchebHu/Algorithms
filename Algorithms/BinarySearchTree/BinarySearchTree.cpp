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

	void preOrder() {
		__preOrder(root);
	}

	void inOrder() {
		__inOrder(root);
	}

	void postOrder() {
		__postOrder(root);
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

	void __preOrder(Node* node) {
		if (node != NULL) {
			std::cout << node->key << std::endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}
	}

	void __inOrder(Node* node) {
		if (node != NULL) {
			__inOrder(node->left);
			std::cout << node->key << std::endl;
			__inOrder(node->right);
		}
	}

	void __postOrder(Node* node) {
		if (node != NULL) {
			__postOrder(node->left);
			__postOrder(node->right);
			std::cout << node->key << std::endl;
		}
	}
};

int main() {
	
	return 0;
}