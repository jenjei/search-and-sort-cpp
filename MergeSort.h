#pragma once

class MergeSort {
public:
    MergeSort();  // default constructor
    MergeSort(int arr[], int size);  // constructor with array input
    void sort();  // sorts the array using merge sort
    void print(int printSize = 200) const;  // prints the array
    int getNumComparisons() const; // returns the number of comparisons made during the sort
    int getNumAssignments() const; // returns the number of assignments made during the sort
private:
    void mergeSort(int low, int high);  // sorts the array recursively
    void merge(int low, int mid, int high);  // merges two sorted subarrays
    int *arr;  // pointer to the array
    int size;  // size of the array
    int numComparisons;
    int numAssignments;
};