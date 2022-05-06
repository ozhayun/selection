#pragma once
#include "Person.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Selection
{


    
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
    int partition(Person personArr[], int left, int right)
    {
        // pivot
        const Person & pivot = personArr[right];

        // Index of smaller element
        int i = (left - 1);

        for (int j = left; j <= right - 1; j++)
        {
            // If current element is smaller
            // than or equal to pivot
            if (personArr[j].id <= pivot.id) {

                // increment index of
                // smaller element
                i++;
                swap(personArr[i], personArr[j]);
            }
        }
        swap(personArr[i + 1], personArr[right]);
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
    int partition_r(Person personArr[], int left, int right)
    {
        // Generate a random number in between
        // low .. high
        srand(time(NULL));
        int random = left + rand() % (right - left);

        // Swap A[random] with A[high]
        swap(personArr[random], personArr[right]);

        return partition(personArr, left, right);
    }

public:
	Person Select(Person personArr[], int left, int right, int i)
	{
		int pivot;
		int leftPart;

        pivot = partition_r(personArr, left, right);

		leftPart = pivot - left + 1;
		if (i == leftPart)
			return personArr[pivot];
		if (i < leftPart)
			return Select(personArr, left, pivot - 1, i);
		else
			return Select(personArr, pivot + 1, right, i - leftPart);
	}

	const Person& RandSelection(Person[], int n, int k, int& NumComp)
	{

	}


	const Person& selectHeap(Person[], int n, int k, int& NumComp)
	{

	}

	const Person& BST(Person[], int n, int k, int& NumComp)
	{

	}

};

