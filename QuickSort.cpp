#include <iostream>

int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void swap(int& a, int& b);

int main() {
	int arr[]{10,5,3,2,1,6,7,8,9,4};
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	quickSort(arr, 0, 10);

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
	return 0;
}


int partition(int arr[], int start, int end) {
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;
	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) return;
	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

void swap(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}