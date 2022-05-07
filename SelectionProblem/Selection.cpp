#include "Selection.h"

const Person& Selection::RandSelection(vector<Person>& personArr, int n, int k, int& numComp) {
	vector<Person> randomSelectionVector(personArr);
	randomPerson = random.Selection(randomSelectionVector, n, k);
	numComp = random.getNumComp();
	return randomPerson;
}

const Person& Selection::selectHeap(vector<Person>& personArr, int n, int k, int& numComp) {
	minHeap.buildHeap(personArr);
	for (int i = 0; i < k - 1; i++) {
		minHeap.deleteMin();
	}
	heapPerson = minHeap.deleteMin();
	numComp = minHeap.getNumComp();
	return heapPerson;
}

const Person& Selection::BST(vector<Person>& personArr, int n, int k, int& numComp) {
	bst.buildBST(personArr);
	bstPerson = bst.select(k - 1);
	numComp = bst.getNumComp();
	return bstPerson;
}