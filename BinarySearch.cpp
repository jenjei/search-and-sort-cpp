#include "BinarySearch.h"
#include <algorithm>
#include <cmath>
#include "SequentialSearch.h"
#include <iomanip>

using namespace std;

int BinarySearch::search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    int mid;
    int comparisons = 0;
    Timer timer;

    while (left <= right) {
        mid = (left + right) / 2;
        comparisons++;

        if (arr[mid] == key) {
            cout << "Binary search successful. ";
            cout << "Key found at index " << mid << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            cout << "Elapsed time: " << round(timer.elapsed_time()) << " seconds" << endl;
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << "Binary search unsuccessful. ";
    cout << "Key not found in array." << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Elapsed time: " << round(timer.elapsed_time()) << " seconds" << endl;

    return -1;
}

void BinarySearch::performanceTest(int size, int numTests) {
    srand(time(NULL));
    int* arr = new int[size];
    int key;
    Timer timer;

    for (int i = 0; i < numTests; i++) {
        // Fill array with random integers
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % (size * 10);
        }

        // Sort array in ascending order
        sort(arr, arr + size);

        // Search for a random key value
        key = rand() % (size * 10);
        cout << "Test " << i+1 << endl;
        cout << "Key value: " << key << endl;

        // Perform sequential search
        cout << "Performing sequential search..." << endl;
        Timer seqTimer;
        int seqResult = SequentialSearch::search(arr, size, key);
        double seqTime = seqTimer.elapsed_time();
        cout << "Sequential search time: " << fixed << setprecision(7) << seqTime << " seconds" << endl;

        // Perform binary search
        cout << "Performing binary search..." << endl;
        Timer binTimer;
        int binResult = BinarySearch::search(arr, size, key);
        double binTime = binTimer.elapsed_time();
        cout << "Binary search time: " << binTime << " seconds" << endl;

        cout << endl;
    }

    delete[] arr;
}