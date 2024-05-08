#include <iostream>

void mergeSort(int* arr, int low, int high);
void mergeSortDescending(int* arr, int low, int high);
void merge(int* arr, int low, int mid, int high);
void mergeDescending(int* arr, int low, int mid, int high);
int mergeSortAndCountInversion(int* arr, int low, int high);
int mergeAndCountInversion(int* arr, int low, int mid, int high);

int main() {
	int arr[]{33,1,55,64,21};
	//mergeSort(arr, 0, 4);
	//mergeSortDescending(arr, 0, 4);
	int inversions = mergeSortAndCountInversion(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << "\n";
    }
	std::cout << "Number of inversions: " << inversions << "\n";

	return 0;
}

// A. Implementing Merge Sort
void mergeSort(int* arr, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


void merge(int* arr, int low, int mid, int high) {
	int leftSubSize = mid - low + 1;
	int rightSubSize = high - mid;

	int *left = new int[leftSubSize], *right = new int[rightSubSize];

	for (int i = 0; i < leftSubSize; i++) {
		left[i] = arr[low + i];
	}

	for (int j = 0; j < rightSubSize; j++) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = 0;

	int* aux = new int[leftSubSize + rightSubSize];

	while (i < leftSubSize && j < rightSubSize) {
		if (left[i] < right[j])
			aux[k] = left[i++];
		else
			aux[k] = right[j++];
		k++;
	}

	while (i < leftSubSize)
		aux[k++] = left[i++];

	while (j < rightSubSize)
		aux[k++] = right[j++];

	for (int i = 0; i < high - low + 1; i++) 
		arr[low + i] = aux[i];

	delete[] left;
	delete[] right;
	delete[] aux;
}


//E. Sorting an array in descending order
void mergeSortDescending(int* arr, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSortDescending(arr, low, mid);
		mergeSortDescending(arr, mid + 1, high);
		mergeDescending(arr, low, mid, high);
	}
}


void mergeDescending(int* arr, int low, int mid, int high) {
	int leftSubSize = mid - low + 1;
	int rightSubSize = high - mid;

	int* left = new int[leftSubSize], * right = new int[rightSubSize];

	for (int i = 0; i < leftSubSize; i++) {
		left[i] = arr[low + i];
	}

	for (int j = 0; j < rightSubSize; j++) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = 0;

	int* aux = new int[leftSubSize + rightSubSize];

	while (i < leftSubSize && j < rightSubSize) {
		if (left[i] >= right[j])
			aux[k] = left[i++];
		else
			aux[k] = right[j++];
		k++;
	}

	while (i < leftSubSize)
		aux[k++] = left[i++];

	while (j < rightSubSize)
		aux[k++] = right[j++];

	for (int i = 0; i < high - low + 1; i++)
		arr[low + i] = aux[i];

	delete[] left;
	delete[] right;
	delete[] aux;
}
int mergeSortAndCountInversion(int* arr, int low, int high) {
	int inversions = 0;
	if (low < high) {
		int mid = low + (high - low) / 2;
		inversions += mergeSortAndCountInversion(arr, low, mid);
		inversions += mergeSortAndCountInversion(arr, mid + 1, high);
		inversions += mergeAndCountInversion(arr, low, mid, high);
	}
	return inversions;
}

int mergeAndCountInversion(int* arr, int low, int mid, int high) {
	int leftSubSize = mid + 1 - low;
	int rightSubSize = high - mid;
	
	int *left = new int[leftSubSize];
	int *right = new int[rightSubSize];
	
	for (int i = 0; i < leftSubSize; i++) {
		left[i] = arr[low + i];
	}
	for (int j = 0; j < rightSubSize; j++) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = 0;

	int inversions = 0;
	int* aux = new int[leftSubSize + rightSubSize];

	while (i < leftSubSize && j < rightSubSize) {
		if (left[i] < right[j]) {
			aux[k] = left[i];
			i++;
		}
		else {
			aux[k] = right[j];
			j++;
			inversions += mid - i;
		}
		k++;
	}

	while (i < leftSubSize) {
		aux[k] = left[i];
		i++;
		k++;
	}
	while (j < rightSubSize) {
		aux[k] = right[j];
		j++;
		k++;
	}

	for (int i = 0; i < leftSubSize + rightSubSize; i++) {
		arr[low + i] = aux[i];
	}

	delete[] left;
	delete[] right;
	delete[] aux;
	return inversions;
}
