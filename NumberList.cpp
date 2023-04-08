#include "NumberList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor
NumberList::NumberList(int size) {
    this->size = size;
    arr = new int[size];
    generateList();
}

// Destructor
NumberList::~NumberList() {
    delete[] arr;
}

// Generates a list of odd integers
void NumberList::generateList() {
    int num = 1;
    for(int i = 0; i < size; i++) {
        arr[i] = num;
        num += 2;
    }
}

// Prints the list of numbers
void NumberList::printList() {
    cout << "List of numbers: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Sets the key value to search for
void NumberList::setKey(int key) {
    this->key = key;
}

// Searches for the key value using linear search
int NumberList::linearSearch() {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Searches for the key value using binary search
int NumberList::binarySearch() {
    int low = 0;
    int high = size - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// Generates a random key value between 1 and size*2
int NumberList::generateKey() {
    srand(time(NULL));
    key = rand() % (size * 2) + 1;
    cout << "The program has generated the number " << key << " for you to search for." << endl;
    return key;
}

// Runs the program
void NumberList::run() {
    cout << "Enter the number you want to search for (or enter 0 to generate a random number): ";
    cin >> key;
    if(key == 0) {
        generateKey();
    }
    int index = linearSearch();
    if(index == -1) {
        cout << key << " was not found using linear search." << endl;
    }
    else {
        cout << key << " was found at index " << index << " using linear search." << endl;
    }
}