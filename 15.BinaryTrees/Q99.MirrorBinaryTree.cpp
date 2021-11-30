/*
       1                        1
    2     3                 3      2
  4   5  6  7             7   6  5   4   
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
BinaryTree<int> *mirror(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = mirror(root->left);
    root->right = mirror(root->right);
    BinaryTree<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    printLineWise(root);
    root = mirror(root);
    cout << "Mirrored: " << endl;
    printLineWise(root);
}