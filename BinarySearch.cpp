#include <iostream>
#include <algorithm>
#include <vector>

// A implementing binary search
int search(int* arr, int value, int len, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end || end < start) {
        return -1;
    }
    if (arr[mid] == value) {
        return mid;
    }
    else if (arr[mid] > value) {
        return search(arr, value, len, start, mid - 1);

    }
    else if (arr[mid] < value) {
        return search(arr, value, len, mid + 1, end);
    }

    return -1;
}

int getFirstOccurr(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int getLastOccurr(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int findPeak(std::vector<int>& vect) {
    int left = 0;
    int right = vect.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vect[mid] > vect[mid + 1]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

void printVector(std::vector<int>& vect) {
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    //           0 1 2 3 4
    int arr[] = { 1,2,3,5,5 };
    std::vector<int> myVect{ 6,1,23,5,1 };

    int size = sizeof(arr) / sizeof(int);
    std::sort(arr, arr + size);
    std::cout << "========" << std::endl;
    std::cout << search(arr, 2, size, 0, size - 1) << std::endl;
    std::cout << "========" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << myVect[findPeak(myVect)] << std::endl;
    std::cout << size << std::endl;
    return 0;
}
