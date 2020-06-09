#pragma once

#include <vector>


template <class T>
void SelectionSort(std::vector<T>& vec) {

	for (size_t i = 0; i < vec.size(); ++i) {
		int minIndex = i;
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[minIndex] > vec[j]) {
				minIndex = j;
			}
		}

		std::swap(vec[minIndex], vec[i]);
	}
}

template <class T>
void BubbleSort(std::vector<T>& vec) {
	auto size = vec.size();
	bool sorted = false;
	for (size_t i = size - 1; i > 0 && !sorted; --i) {
		sorted = true;
		for (size_t j = 0; j < i; ++j) {
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
				sorted = false;
			}
		}
	}
}

template <class T>
void InsertionSort(std::vector<T>& vec) {
	auto size = vec.size();
	for (size_t i = 1; i < size; ++i) {
		for (size_t j = i; j > 0 && vec[j] < vec[j - 1]; --j) {
			std::swap(vec[j], vec[j - 1]);
		}
	}
}


std::vector<int> aux;

template <class T>
void MergeSort(std::vector<T>& vec, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	for (int k = low; k <= high; ++k) {
		aux[k] = vec[k];
	}

	for (int k = low; k <= high; ++k) {
		if (i > mid) {
			vec[k] = aux[j++];
		}
		else if (j > high) {
			vec[k] = aux[i++];
		}
		else if (aux[j] < aux[i]) {
			vec[k] = aux[j++];
		}
		else {
			vec[k] = aux[i++];
		}
	}
}


template <class T>
void MergeSort(std::vector<T>& vec, int low, int high) {
	if (low >= high)
		return;
	auto mid = low + (high - low) / 2;
	MergeSort(vec, low, mid);
	MergeSort(vec, mid + 1, high);
	MergeSort(vec, low, mid, high);
}


template <class T>
void MergeSort(std::vector<T>& vec) {
	aux = std::vector<T>(vec.size());
	MergeSort(vec, 0, vec.size() - 1);
}

template <class T>
int Partition(std::vector<T>& vec, int low, int high) {
	int i = low;
	int j = high + 1;
	T v = vec[low];

	while (true) {
		while (vec[++i] < v && i != high)
			;
		while (vec[--j] > v&& j != low)
			;

		if (i >= j) {
			std::swap(vec[low], vec[j]);
			return j;
		}

		std::swap(vec[i], vec[j]);
	}

	/*std::swap(vec[low], vec[j]);
	return j;*/
}

template <class T>
void QuickSort(std::vector<T>& vec, int low, int high) {
	if (low >= high)
		return;
	int j = Partition(vec, low, high);
	QuickSort(vec, low, j - 1);
	QuickSort(vec, j + 1, high);
}

template <class T>
void QuickSort(std::vector<T>& vec) {
	QuickSort(vec, 0, vec.size() - 1);
}

template <class T>
class Heap {
private:
	std::vector<T> heap;
	int n;

public:
	Heap(int maxSize) : heap(std::vector<T>(maxSize)), n(maxSize + 1) {}

	bool isEmpty() {
		return n == 0;
	}

	int size() {
		return n;
	}
	void insert(T value) {
		heap[++n] = T;
		swim(n);
	}

	void deleteMax() {
		heap[1] = heap[n];
		heap[n--] = NULL;
		sink(1);
	}

private:
	void swim(int k) {
		while (k > 1 && heap[k] > heap[k / 2]) {
			std::swap(heap[k], heap[k / 2]);
			k /= 2;
		}
	}

	void sink(int k) {
		while (2 * k <= n) {
			int j = 2 * k;
			if (j < n && heap[j] < heap[j + 1])
				++j;
			if (heap[k] < heap[j])
				break;
			std::swap(heap[k], heap[j]);
			k = j;
		}
	}
};

template <class T>
void sink(std::vector<T>& vec, int k, int n) {
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int maxIndex = k;
	if (left < n && vec[left] > vec[maxIndex])
		maxIndex = left;
	if (right < n && vec[right] > vec[maxIndex])
		maxIndex = right;

	if (maxIndex != k) {
		std::swap(vec[k], vec[maxIndex]);
		sink(vec, maxIndex, n);
	}
}

template <class T>
void HeapSort(std::vector<T>& vec) {
	int size = vec.size();
	for (int k = size / 2 - 1; k >= 0; --k) {
		sink(vec, k, size);
	}

	for (int i = size - 1; i > 0; --i) {
		std::swap(vec[0], vec[i]);
		sink(vec, 0, i);
	}
}
