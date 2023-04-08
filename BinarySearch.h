#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "timer.h"

class BinarySearch {
public:
    static int search(int arr[], int size, int key);
    static void performanceTest(int size, int numTests);
};