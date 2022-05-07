#pragma once

// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include <vector>
#include "Person.h"

using std::vector;

// A class for Min Heap
class MinHeap
{
    int _numComp = 0;
    // pointer to array of elements in heap
    vector<Person> data; 
    // maximum possible size of min heap
    int maxSize; 
    // Current number of elements in min heap
    int heapSize;
     // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }
    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    int parent(int i) { return (i - 1) / 2; }

    void fixHeap(int i);
public:
    // Constructor
    void buildHeap(vector<Person> & personArr);
    int getNumComp() { return _numComp; }
    Person deleteMin();
    void insert(Person p);
};

