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

    node* makeEmpty(node* t) {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(Person x, node* t)
    {
        if (t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (++_numComp && x.id < t->data.id)
            t->left = insert(x, t->left);
        else if (++_numComp && x.id > t->data.id)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int id, node* t) {
        node* temp;
        if (t == NULL)
            return NULL;
        else if (++_numComp && id < t->data.id)
            t->left = remove(id, t->left);
        else if (++_numComp && id > t->data.id)
            t->right = remove(id, t->right);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data.id, t->right);
        }
        else {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    node* find(node* t, int id) {
        if (t == NULL)
            return NULL;
        else if (++_numComp && id < t->data.id)
            return find(t->left, id);
        else if (++_numComp && id > t->data.id)
            return find(t->right, id);
        else
            return t;
    }

    void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data.id << " ";
        inorder(t->right);
    }

    int size(node* root) {
        //base case
        if (root == NULL)
            return 0;

        //recursive call to left child and right child and
        // add the result of these with 1 ( 1 for counting the root)
        return 1 + size(root->left) + size(root->right);
    }

    node* select(node* x, int k) {
        if (x == NULL) return NULL;
        int t = size(x->left);
        if (t > k) return select(x->left, k);
        else if (t < k) return select(x->right, k - t - 1);
        else            return x;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(Person p) {
        root = insert(p, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void search(int x) {
        root = find(root, x);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    int getNumComp() { return _numComp; }

    void buildBST(vector<Person>& personArr) {
        for (auto i = personArr.begin(); i != personArr.end(); i++)
            insert(*i);
    }

    const Person& select(int k) {
        node* n = select(root, k);
        return n->data;
    }
};

