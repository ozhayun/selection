#include "MinHeap.h"

// Builds a heap from a given array a[] of given size
void MinHeap::buildHeap(vector<Person>& personArr) {
    heapSize = maxSize = personArr.size();

    data = personArr;
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        fixHeap(i);
}

Person MinHeap::deleteMin() {
    if (heapSize < 1) {
        // TODO: handle Error
    }
    Person min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    fixHeap(0);
    return Person(min);
}

void MinHeap::fixHeap(int i) {
    int min;
    int left = this->left(i);
    int right = this->right(i);

    if ((left < heapSize) && ++_numComp && (data[left].id < data[i].id))
        min = left;
    else
        min = i;

    if ((right < heapSize) && ++_numComp && (data[right].id < data[min].id))
        min = right;

    if (min != i) {
        swap(data[i], data[min]);
        fixHeap(min);
    }
}

void MinHeap::insert(Person p) {
    if (heapSize == maxSize) {
        //Handle error
    }
    int i = heapSize;
    heapSize++;

    while ((i > 0) && ++_numComp && (data[this->parent(i)].id > p.id) ) {
        data[i] = data[this->parent(i)];
        i = this->parent(i);
    }
    data[i] = p;
}

