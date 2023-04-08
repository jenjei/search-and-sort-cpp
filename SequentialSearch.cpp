#include "SequentialSearch.h"
#include <iostream>
using namespace std;

int SequentialSearch::search(int arr[], int size, int key) {
    int comparisons = 0;

    for (int i = 0; i < size; i++) {
        comparisons++;

        if (arr[i] == key) {
            cout << "Sequential search successful. ";
            cout << "Key found at index " << i << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return i;
        }
    }

    cout << "Sequential search unsuccessful. ";
    cout << "Key not found in array." << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return -1;
}