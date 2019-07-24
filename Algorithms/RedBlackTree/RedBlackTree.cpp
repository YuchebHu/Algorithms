#include "RedBlackTree.h"

int main() {
	RedBlackTree<size_t, size_t> tree;
	for (size_t i = 0; i < 1000000; ++i)
		tree.insert(i, i);

	//tree.preOrder();
	//std::cout << std::endl;
	//tree.inOrder();
	//std::cout << std::endl;
	//tree.postOrder();
	std::cout << tree.Height();
	return 0;
}