#include "InsertionSort.h"
#include <iostream>

using namespace std;

InsertionSort::InsertionSort() : arr(nullptr), size(0), numComparisons(0), numAssignments(0) {}

InsertionSort::InsertionSort(int arr[], int size) : arr(new int[size]), size(size), numComparisons(0), numAssignments(0) {
    for (int i = 0; i < size; i++) {
        this->arr[i] = arr[i];
    }
}

void InsertionSort::sort() {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            numComparisons++;
            numAssignments++;
        }
        arr[j + 1] = key;
        numAssignments++;
    }
}

void InsertionSort::print(int printSize) const {
    printSize = min(size, printSize);
    for (int i = 0; i < printSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int InsertionSort::getNumComparisons() const {
    return numComparisons;
}

int InsertionSort::getNumAssignments() const {
    return numAssignments;
}

void InsertionSort::sortInput() {
    cout << "Enter the number of elements to be sorted: ";
    cin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element #" << i+1 << ": ";
        cin >> arr[i];
    }

    sort();
}