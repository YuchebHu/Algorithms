#pragma once

#include <vector>

template <class T>
void BubbleSort(std::vector<T>& vec) {
	auto size = vec.size();
	bool isSorted = false;
	for (int i = 0; i < size && !isSorted; ++i) {
		isSorted = true;
		for (int j = size - 1; j > i; --j) {
			if (vec[j] < vec[j - 1]) {
				std::swap(vec[j], vec[j - 1]);
				isSorted = false;
			}
		}
	}
}

template <class T>
void InsertionSort(std::vector<T>& vec) {
	auto size = vec.size();
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0 && vec[j] < vec[j - 1]; --j) {
			std::swap(vec[j], vec[j - 1]);
		}
	}
}

template <class T>
void SelectionSort(std::vector<T>& vec) {
	auto size = vec.size();
	for (int i = 0; i < size; ++i) {
		int maxIdx = i;
		for (int j = i + 1; j < size; ++j) {
			if (vec[maxIdx] > vec[j])
				maxIdx = j;
		}

		std::swap(vec[maxIdx], vec[i]);
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
		else if (aux[i] <= aux[j]) { // 保证排序的稳定性
			vec[k] = aux[i++];
		}
		else {
			vec[k] = aux[j++];
		}
	}
}

template <class T>
void MergeSort(std::vector<T>& vec, int low, int high) {
	if (low >= high)
		return;
	int mid = low + (high - low) / 2;
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
	T target = vec[low];

	while (true) {
		while (vec[++i] < target && i != high);
		while (vec[--j] > target && j != low);
		if (i >= j) {
			std::swap(vec[low], vec[j]);
			return j;
		}
		std::swap(vec[i], vec[j]);
	}
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
void shiftDown(std::vector<T>& vec, int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && vec[j] < vec[j + 1])
			++j;
		if (vec[j] < vec[k])
			break;
		std::swap(vec[k], vec[j]);
		k = j;
	}
}

template <class T>
void HeapSort(std::vector<T>& vec) {
	int size = vec.size();
	for (int k = (size - 1) / 2; k >= 0; --k) {
		shiftDown(vec, size, k);
	}

	for (int k = size - 1; k > 0; --k) {
		std::swap(vec[0], vec[k]);
		shiftDown(vec, k, 0);
	}
}