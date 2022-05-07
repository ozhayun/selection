#pragma once
#include<iostream>
#include "Person.h"
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class BST {
    struct node {
        Person data;
        node* left;
        node* right;
    };

    int _numComp = 0;
    node* root;

    node* makeEmpty(node* t);

    node* insert(Person x, node* t);

    node* findMin(node* t);

    node* findMax(node* t);

    node* remove(int id, node* t);

    node* find(node* t, int id);

    void inorder(node* t);

    int size(node* root);

    node* select(node* x, int k);

public:
    BST() { root = NULL; }

    ~BST() { root = makeEmpty(root); }

    void insert(Person p) { root = insert(p, root); }

    void remove(int x) { root = remove(x, root); }

    void search(int x) { root = find(root, x); }

    int getNumComp() { return _numComp; }

    void display() {
        inorder(root);
        cout << endl;
    }

    void buildBST(vector<Person>& personArr) {
        for (auto i = personArr.begin(); i != personArr.end(); i++)
            insert(*i);
    }

    const Person& select(int k) {
        node* n = select(root, k);
        return n->data;
    }
};

