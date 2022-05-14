#include "Random.h"

int Random::partition(vector<Person>& personArr, int left, int right) {
    // pivot
    const Person& pivot = personArr[right];

    // Index of smaller element
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        // If current element is smaller
        // than or equal to pivot
        if (personArr[j].id <= pivot.id) {
            _numComp++;
            // increment index of
            // smaller element
            i++;
            swap(personArr[i], personArr[j]);
        }
    }
    swap(personArr[i + 1], personArr[right]);
    return (i + 1);
}

int Random::partition_r(vector<Person>& personArr, int left, int right) {
    int random = left + rand() % (right - left);

    swap(personArr[random], personArr[right]);

    return partition(personArr, left, right);
}

const Person& Random::SelectionUtil(vector<Person>& personArr, int left, int right, int k) {
    int pivot;
    int leftPart;

    if (left == right)
        return personArr[left];

    pivot = partition_r(personArr, left, right);

    leftPart = pivot - left + 1;
    if (k == leftPart)
        return personArr[pivot];
    if (k < leftPart)
        return SelectionUtil(personArr, left, pivot - 1, k);
    else
        return SelectionUtil(personArr, pivot + 1, right, k - leftPart);
}

const Person& Random::Selection(vector<Person>& personArr, int n, int k) {
    const Person& p = SelectionUtil(personArr, 0, n - 1, k);
    return p;
}