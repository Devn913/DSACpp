/*
Given a BST, Print numbers from BST within a range
*/
#include "iostream"
#include "queue"
#include <bits/stdc++.h>
#include "math.h"
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree(T val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
BinaryTree<int> *inputLineWise()
{
    cout << "Enter root data: ";
    int data;
    cin >> data;
    BinaryTree<int> *root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *front = q.front();
        q.pop();
        int val;
        cout << "Enter left val for " << front->data << " -1 for NULL: ";
        cin >> val;
        if (val != -1)
        {
            front->left = new BinaryTree<int>(val);
            q.push(front->left);
        }
        cout << "Enter right val for " << front->data << " -1 for NULL: ";
        cin >> val;
        if (val != -1)
        {
            front->right = new BinaryTree<int>(val);
            q.push(front->right);
        }
    }
    return root;
}
void printInRange(BinaryTree<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= min, root->data <= max)
    {
        cout << root->data << " ";
    }
    if (root->left != NULL && root->left->data >= min && root->left->data <= max)
    {
        printInRange(root->left, min, max);
    }
    if (root->right != NULL && root->right->data <= max && root->right->data >= min)
    {
        printInRange(root->right, min, max);
    }
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    printInRange(root, 10, 40);
}