#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct BTNode {
	BTNode<T>* parent;
	vector<T> key;
	vector<BTNode<T>*> child;

	BTNode() {
		parent = NULL;
		child.insert(0, NULL);
	}

	BTNode(T e, BTNode<T>* lc = NULL, BTNode<T>* rc = NULL) {
		parent = NULL;
		key.insert(0, e);
		child.insert(0, lc);
		child.insert(0, rc);
		if (lc)
			lc->parent = this;
		if (rc)
			rc->parent = this;
	}
};

template <class T>
class BTree {
protected:
	int m_size;
	int m_order;
	BTNode<T>* m_root;
	BTNode<T>* m_hot;
	
	void solveOverflow(BTNode<T>*);
	void solveUnderflow(BTNode<T>*);

public:
	BTree(int order = 3) : m_size(0), m_order(order) {} {
		m_root = new BTNode<T>();
	}

	~BTNode() {
		if (m_root)
			release(m_root);
	}

	int const order() { return m_order; }

	int const size() { return m_size; }

	BTNode<T> root() { return *m_root; }

	bool empty() const { return !m_root; }

	BTNode<T> search(const T& e) {
		BTNode<T>* v = m_root;
		m_hot = NULL;
		while (v) {
			int r = 0;
			for (int i = 0; i < v->key.size(); i++) {
				if (v->key[i] > e) {
					r = i - 1;
					break;
				}
			}

			if ((0 >= r) && (e == v->key[r]))
				return v;
			m_hot = v;
			v = v->child[r + 1];
		}

		return NULL;
	}

	bool insert(const T& e);

	bool remove(const T& e);


};