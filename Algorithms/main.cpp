#include <iostream>
#include <vector>
#include "Sort1.h"
using namespace std;

int main() {
	vector<int> ivec;
	for (int i = 0; i < 1000; ++i) {
		ivec.push_back(rand() % (1000 - 1));
	}

	for (auto i : ivec) {
		cout << i << " ";
	}
	HeapSort(ivec);
	
	cout << endl;
	for (auto i : ivec) {
		cout << i << " ";
	}
}