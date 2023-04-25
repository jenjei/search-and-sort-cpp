#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort() {
    arr = nullptr;
    size = 0;
    numComparisons = 0;
    numAssignments = 0;
}

MergeSort::MergeSort(int arr[], int size) {
    this->arr = new int[size];
    for (int i = 0; i < size; i++) {
        this->arr[i] = arr[i];
    }
    this->size = size;
    numComparisons = 0;
    numAssignments = 0;
}

void MergeSort::sort() {
    mergeSort(0, size - 1);
}

void MergeSort::mergeSort(int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
}

void MergeSort::merge(int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[low + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        numComparisons++;
        numAssignments++;
        k++;
    }
    while (i < leftSize) {
        arr[k] = leftArr[i];
        numAssignments++;
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        numAssignments++;
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort::print(int printSize) const {
    cout << "Array: ";
    if (size <= printSize) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = 0; i < printSize / 2; i++) {
            cout << arr[i] << " ";
        }
        cout << "... ";
        for (int i = size - printSize / 2; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int MergeSort::getNumComparisons() const {
    return numComparisons;
}

int MergeSort::getNumAssignments() const {
    return numAssignments;
}