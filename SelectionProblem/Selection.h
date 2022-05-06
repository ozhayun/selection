#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Selection {
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
    int partition(vector<Person>& personArr, int left, int right, int& NumComp) {
        // pivot
        const Person & pivot = personArr[right];

        // Index of smaller element
        int i = (left - 1);

        for (int j = left; j <= right - 1; j++) {
            // If current element is smaller
            // than or equal to pivot
            if (personArr[j].id <= pivot.id) {
                NumComp++;
                // increment index of
                // smaller element
                i++;
                swap(personArr[i], personArr[j]);
            }
        }
        swap(personArr[i+1], personArr[right]);
        return (i + 1);
    }


    /*
    @ params:
        * personArr[] --> Array to be selected,
        * left --> Starting index,
        * right --> Ending index
    @ descripion:
        * Generates Random Pivot, swaps pivot with
        * end element and calls the partition function
    */
    int partition_r(vector<Person>& personArr, int left, int right, int& NumComp) {
        // Generate a random number in between
        // low .. high
        srand(time(NULL));

        int random = left + rand() % (right - left);

        swap(personArr[random], personArr[right]);

        return partition(personArr, left, right, NumComp);
    }
public:
    const Person& RandSelectionUtil(vector<Person>& personArr, int left, int right, int k, int& NumComp) {
		int pivot;
		int leftPart;

        if (left == right)
            return personArr[left];

        pivot = partition_r(personArr, left, right, NumComp);

		leftPart = pivot - left + 1;
		if (k == leftPart)
			return personArr[pivot];
		if (k < leftPart)
			return RandSelectionUtil(personArr, left, pivot - 1, k, NumComp);
		else
			return RandSelectionUtil(personArr, pivot + 1, right, k - leftPart, NumComp);
	}

    const Person& RandSelection(vector<Person>& personArr, int n, int k, int& NumComp) {
        return RandSelectionUtil(personArr, 0, n - 1, k, NumComp);
	}


	const Person& selectHeap(vector<Person>& personArr, int n, int k, int& NumComp)
	{

	}

	const Person& BST(vector<Person>& personArr, int n, int k, int& NumComp)
	{

	}

};

