/*
Search for a node in a Binary search tree
 7 8 9 10 11 12 13
        10
    8       12
  7   9   11  13
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
BinaryTree<int> *search(BinaryTree<int> *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    BinaryTree<int> *res = search(root, 10);
    if (res == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
}
