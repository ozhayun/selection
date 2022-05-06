#pragma once

#include "Person.h"
#include <vector>
#include <ctime>

using std::vector;

class Random {
    int _numComp = 0;

/*
@ descripion:
    * This function takes last element
    * as pivot, places
    * the pivot element at its correct
    * position in sorted array, and
    * places all smaller (smaller than pivot)
    * to left of pivot and all greater
    * elements to right of pivot
*/
    int partition(vector<Person>& personArr, int left, int right);

    /*
    @ params:
        * personArr[] --> Array to be selected,
        * left --> Starting index,
        * right --> Ending index
    @ descripion:
        * Generates Random Pivot, swaps pivot with
        * end element and calls the partition function
    */
    int partition_r(vector<Person>& personArr, int left, int right);

    const Person& SelectionUtil(vector<Person>& personArr, int left, int right, int k);

public:
    const Person& Selection(vector<Person>& personArr, int n, int k, int& numComp);
};

