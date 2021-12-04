/*
Create a BST from a sorted Array
*/
#include "iostream"
#include "queue"
#include <bits/stdc++.h>
#include "math.h"
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<int> *next;
    Node(T val)
    {
        data = val;
        next = NULL;
    }
    Node()
    {
        next = NULL;
    }
};

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

Node<int> *BSTtoLL(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node<int> *head = new Node<int>;
    head = BSTtoLL(root->left);
    Node<int> *temp = head;
    Node<int> *rootNode = new Node<int>(root->data);
    rootNode->next = BSTtoLL(root->right);
    if (temp == NULL)
    {
        return rootNode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = rootNode;
    return head;
}

int main()
{
    BinaryTree<int> *root = inputLineWise();
    Node<int> *head = BSTtoLL(root);
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
}