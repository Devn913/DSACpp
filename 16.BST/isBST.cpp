/*
Check is the given tree is a BST
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
pair<pair<int, int>, bool> isBST(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> max_min(INT_MIN, INT_MAX);
        pair<pair<int, int>, bool> res(max_min, true);
        return res;
    }
    pair<pair<int, int>, bool> left = isBST(root->left);
    pair<pair<int, int>, bool> right = isBST(root->right);
    bool val = left.second && right.second && (root->data <= right.first.second) && (root->data > left.first.first);
    pair<int, int> max_min(max(root->data, max(left.first.first, right.first.first)), min(root->data, min(left.first.second, left.first.second)));
    pair<pair<int, int>, bool> res(max_min, val);
    return res;
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    pair<pair<int, int>, bool> res = isBST(root);
    if (res.second)
    {
        cout << "Yes a BST" << endl;
    }
    else
    {
        cout << "Not a BST" << endl;
    }
}