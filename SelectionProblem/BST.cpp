#include "BST.h"

struct node;

BST::node* BST::makeEmpty(node* t) {
    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

BST::node* BST::insert(Person x, node* t) {
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

BST::node* BST::findMin(node* t) {
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

BST::node* BST::findMax(node* t) {
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

BST::node* BST::remove(int id, node* t) {
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

BST::node* BST::find(node* t, int id) {
    if (t == NULL)
        return NULL;
    else if (++_numComp && id < t->data.id)
        return find(t->left, id);
    else if (++_numComp && id > t->data.id)
        return find(t->right, id);
    else
        return t;
}

void BST::inorder(node* t) {
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data.id << " ";
    inorder(t->right);
}

int BST::size(node* root) {
    //base case
    if (root == NULL)
        return 0;

    //recursive call to left child and right child and
    // add the result of these with 1 ( 1 for counting the root)
    return 1 + size(root->left) + size(root->right);
}

BST::node* BST::select(node* x, int k) {
    if (x == NULL) return NULL;
    int t = size(x->left);
    if (t > k) return select(x->left, k);
    else if (t < k) return select(x->right, k - t - 1);
    else            return x;
}