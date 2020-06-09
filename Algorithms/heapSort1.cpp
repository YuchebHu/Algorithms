#include <iostream>
#include <algorithm>
#include <string>
#include "Heap.h"


using namespace std;

template <class T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for (int i = 0; i < n; ++i) {
		maxHeap.insert(arr[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		arr[i] = maxHeap.extractMax();
	}
}
template <class T>
void heapSort2(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

	for (int i = n - 1; i >= 0; --i) {
		arr[i] = maxHeap.extractMax();
	}
}

template <class T>
void shiftDown(T arr, int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && arr[j] < arr[j + 1])
			++j;
		if (arr[k] > arr[j])
			break;

		swap(arr[k], arr[j]);
		k = j;


	}
}

template <class T>
void heapSort(T arr[], int n) {
	for (int i = (n - 1) / 2; i >= 0; --i) {
		__shiftDown(arr, n, i);
	}

	for (int i = n - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}
int main() {
	int a[100];
	for (int i = 0; i < 100; ++i) {
		a[i] = rand() % 1000;
	}

	heapSort1(a, 100);
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}
