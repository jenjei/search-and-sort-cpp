#pragma once


class InsertionSort {
public:
    InsertionSort();  // default constructor
    InsertionSort(int arr[], int size);  // constructor with array input
    void sort();  // sorts the array using insertion sort
    void print(int printSize = 200) const;  // prints the array
    int getNumComparisons() const;  // returns the number of comparisons made during the sort
    int getNumAssignments() const;  // returns the number of assignments made during the sort
    void sortInput();
private:
    int *arr;  // pointer to the array
    int size;  // size of the array
    int numComparisons;  // counter for the number of comparisons made during the sort
    int numAssignments;  // counter for the number of assignments made during the sort
}; 