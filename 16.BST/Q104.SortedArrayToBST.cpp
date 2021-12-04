/*
Create a BST from a sorted Array
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

BinaryTree<int> *toBST(int arr[], int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }

    int mid = (si + ei) / 2;
    BinaryTree<int> *root = new BinaryTree<int>(arr[mid]);
    root->left = toBST(arr, si, mid - 1);
    root->right = toBST(arr, mid + 1, ei);
    return root;
}
void printLineWise(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";

        if (front->left != NULL)
        {
            cout << "L " << front->left->data << " ";
            q.push(front->left);
        }
        if (front->left != NULL)
        {
            cout << "R " << front->right->data << " ";
            q.push(front->right);
        }
        cout << endl;
    }
}
int main()
{
    int *arr = new int[7];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    arr[6] = 7;

    BinaryTree<int> *root = toBST(arr, 0, 6);
    printLineWise(root);
}