/*
Find a Node with given data in a binary tree 
*/
#include "iostream"
#include "queue"
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree(T _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};
BinaryTree<int> *inputLinewise()
{
    int data;
    cout << "Enter the data for root ";
    cin >> data;
    BinaryTree<int> *root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *front = q.front();
        q.pop();
        int data;
        cout << "Enter the left data for left node of " << front->data << " :";
        cin >> data;
        if (data != -1)
        {
            BinaryTree<int> *left = new BinaryTree<int>(data);
            q.push(left);
            front->left = left;
        }
        cout << "Enter the data for right node of " << front->data << " :";
        cin >> data;
        if (data != -1)
        {
            BinaryTree<int> *right = new BinaryTree<int>(data);
            q.push(right);
            front->right = right;
        }
    }
    return root;
}
BinaryTree<int> *searchANode(BinaryTree<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    BinaryTree<int> *left = searchANode(root->left, data);
    if (left != NULL)
    {
        return left;
    }
    BinaryTree<int> *right = searchANode(root->right, data);
    if (right != NULL)
    {
        return right;
    }
    return NULL;
}
int main()
{
    BinaryTree<int> *root = inputLinewise();
    cout << "Enter the data for the you want to search: ";
    int data;
    cin >> data;
    BinaryTree<int> *node = searchANode(root, data);
    if (node == NULL)
    {
        cout << "Node not found. " << endl;
    }
    else
    {
        cout << "Found Node." << endl;
    }
}