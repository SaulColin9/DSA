#include <iostream>
#include <string>
#include <algorithm>

template <class T>
void quickSort(T [], int, int);

template <class T>
int partition(T [], int, int);


int main() {
	std::string arr[]{"hello", "saul", "bye"};
	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
	quickSort<std::string>(arr, 0,2);
	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
	return 0;
}

template <class T>
void quickSort(T arr[], int start, int end) {
	if (start >= end) return;

	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

template <class T>
int partition(T arr[],int start, int end) {
	T pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	std::swap(arr[start], arr[pivotIndex]);
	int i = start, j = end;
	
	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;

}
