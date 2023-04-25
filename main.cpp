#include <iostream>
#include "NumberList.h"
#include "BinarySearch.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void searchSequential() {
    cout << "\033[1;35mSEQUENTIAL AND BINARY SEARCH\033[0m" << endl;
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;

    NumberList list(size);
    list.printList();

    int key;
    cout << "Enter the number you want to search for (or enter 0 to generate a random number): ";
    cin >> key;

    if (key == 0) {
        key = list.generateKey();
    }

    list.setKey(key);
    int index = list.linearSearch();

    if (index == -1) {
        cout << key << " was not found using linear search." << endl;
    }
    else {
        cout << key << " was found at index " << index << " using linear search." << endl;
    }

    index = list.binarySearch();
    if (index == -1) {
        cout << key << " was not found using binary search." << endl;
    }
    else {
        cout << key << " was found at index " << index << " using binary search." << endl;
    }
}

void performanceComparisonBinary() {
    cout << "\033[1;35mBINARY SEARCH PERFORMANCE COMPARISON\033[0m" << endl;
    int size, numTests;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the number of tests to run: ";
    cin >> numTests;

    BinarySearch::performanceTest(size, numTests);
}

void insertionSortMenu() {
    cout << "\033[1;35mINSERTION SORT\033[0m" << endl;
    int size;
    cout << "Enter the size of the array to be sorted: ";
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10);
    }

    cout << "Original array:" << endl;
    InsertionSort insertionSort(arr, size);
    insertionSort.print();

    insertionSort.sort();

    cout << "Sorted array:" << endl;
    insertionSort.print();

    delete[] arr;
}

void mergeSortMenu() {
    cout << "\033[1;35mMERGE SORT\033[0m" << endl;
    int size;
    cout << "Enter the size of the array to be sorted: ";
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10);
    }

    MergeSort mergeSort(arr, size);
    cout << "Unsorted array:" << endl;
    mergeSort.print();
    mergeSort.sort();
    cout << "Sorted array:" << endl;
    mergeSort.print();
    cout << "Number of comparisons: " << mergeSort.getNumComparisons() << endl;
    cout << "Number of assignments: " << mergeSort.getNumAssignments() << endl;

    delete[] arr;
}

void mergeAndInsertionComparison() {
    cout << "\033[1;35mMERGE SORT ADN INSERTION SORT COMPARISON\033[0m" << endl;
    int sizes[] = { 100, 500, 1000, 5000, 10000 };
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    cout << "INSERTION SORT" << endl;
    cout << setw(8) << "Size" << setw(15) << "Num Ops" << setw(30) << "(Comparisons, Assignments)" << setw(10) << "Time" << endl;

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];

        int *arr = new int[size];

        // generate random data for the array
        for (int j = 0; j < size; j++) {
            int value = rand() % (size * 10);
            arr[j] = value;
        }

        // sort with insertion sort and time it
        InsertionSort insertionSort(arr, size);
        clock_t startInsertionSort = clock();
        insertionSort.sort();
        clock_t endInsertionSort = clock();
        double timeInsertionSort = double(endInsertionSort - startInsertionSort) / CLOCKS_PER_SEC;

        // print the results
        cout << setw(8) << size;
        cout << setw(15) << insertionSort.getNumComparisons() + insertionSort.getNumAssignments();
        cout << setw(5) << "(" << insertionSort.getNumComparisons() << ", " << insertionSort.getNumAssignments() << ")";
        if (i==0) {
            cout << setw(28) << fixed << setprecision(6) << timeInsertionSort << " secs" << endl;
        }
        if (i==1) {
            cout << setw(26) << fixed << setprecision(6) << timeInsertionSort << " secs" << endl;
        }
        if (i==2) {
            cout << setw(24) << fixed << setprecision(6) << timeInsertionSort << " secs" << endl;
        }
        if (i==3) {
            cout << setw(22) << fixed << setprecision(6) << timeInsertionSort << " secs" << endl;
        }
        if (i==4) {
            cout << setw(20) << fixed << setprecision(6) << timeInsertionSort << " secs" << endl;
        }
        delete[] arr;
    }

    cout << endl;
    cout << "MERGE SORT" << endl;
    cout << setw(8) << "Size" << setw(15) << "Num Ops" << setw(30) << "(Comparisons, Assignments)" << setw(10) << "Time" << endl;

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];

        int *arr = new int[size];

        for (int j = 0; j < size; j++) {
            int value = rand() % (size * 10);
            arr[j] = value;
        }

        MergeSort mergeSort(arr, size);
        clock_t startMergeSort = clock();
        mergeSort.sort();
        clock_t endMergeSort = clock();
        double timeMergeSort = double(endMergeSort - startMergeSort) / CLOCKS_PER_SEC;

        cout << setw(8) << size;
        cout << setw(15) << mergeSort.getNumComparisons() + mergeSort.getNumAssignments();
        cout << setw(5) << "(" << mergeSort.getNumComparisons() << ", " << mergeSort.getNumAssignments() << ")";
        if (i==0) {
            cout << setw(30) << fixed << setprecision(6) << timeMergeSort << " secs" << endl;
        }
        if (i==1 || i==2) {
            cout << setw(28) << fixed << setprecision(6) << timeMergeSort << " secs" << endl;
        }
        if (i==3) {
            cout << setw(26) << fixed << setprecision(6) << timeMergeSort << " secs" << endl;
        }
        if (i==4) {
            cout << setw(24) << fixed << setprecision(6) << timeMergeSort << " secs" << endl;
        }

        delete[] arr;
    }
}

int main() {

    srand(time(NULL));

    int choice;
    while (true) {
        cout << "\033[1;35mSelect a function to run:\033[0m" << endl;
        cout << "1. Sequential and Binary Search" << endl;
        cout << "2. Binary search performance comparison" << endl;
        cout << "3. Insertion sort" << endl;
        cout << "4. Merge sort" << endl;
        cout << "5. Merge and insertion comparison" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchSequential();
                break;
            case 2:
                performanceComparisonBinary();
                break;
            case 3:
                insertionSortMenu();
                break;
            case 4:
                mergeSortMenu();
                break;
            case 5:
                mergeAndInsertionComparison();
                break;
            case 6:
                cout << "\033[1;31mQuitting program...\033[0m" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again. Numbers 1-6 are valid inputs." << endl;
                break;
        }
    }
    
}