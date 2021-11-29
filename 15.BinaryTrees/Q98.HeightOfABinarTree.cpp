/*
Question: Find the height of binary Tree
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
    cout << "Enter the data for root node: ";
    int data;
    cin >> data;
    BinaryTree<int> *root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *front = q.front();
        q.pop();
        int data;
        cout << "Enter the data of left node for " << front->data << " -1 for NULL: ";
        cin >> data;
        if (data != -1)
        {
            BinaryTree<int> *left = new BinaryTree<int>(data);
            q.push(left);
            front->left = left;
        }
        cout << "Enter the data of right node for " << front->data << " -1 for NULL: ";
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
int heightOfBinaryTree(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    if (left > right)
    {
        return left + 1;
    }
    return right + 1;
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    cout << "Height of the binary tree : " << heightOfBinaryTree(root);
}