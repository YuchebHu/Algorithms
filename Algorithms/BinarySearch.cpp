#include <iostream>

template <typename T>
int BinarySearch(T arr[], int n, T target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

template <typename T>
int BinarySearch1(T arr[], int left, int right, T target) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
		return BinarySearch1(arr, left, right, target);
	}
	return -1;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	std::cout << "Search n: " << BinarySearch(arr, 10, 5);
	std::cout << "\nSearch n: " << BinarySearch(arr, 10, 11);
	std::cout << "\nSearch n: " << BinarySearch1(arr, 0, 9, 0);
	return 0;
}