#include <iostream>
#include "NumberList.h"
#include "BinarySearch.h"

using namespace std;

void searchSequential() {
    cout << "SEQUENTIAL SEARCH" << endl;
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

void searchBinary() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the search key: ";
    cin >> key;

    BinarySearch::search(arr, size, key);

    delete[] arr;
}

void performanceComparisonBinary() {
    int size, numTests;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the number of tests to run: ";
    cin >> numTests;

    BinarySearch::performanceTest(size, numTests);
}


int main() {

    srand(time(NULL));

    int choice;
    while (true) {
        cout << "Select a function to run:" << endl;
        cout << "1. Sequential Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Binary search performance comparison" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchSequential();
                break;
            case 2:
                searchBinary();
            case 3:
                performanceComparisonBinary();
                break;
            case 4:
                cout << "Quitting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    
}