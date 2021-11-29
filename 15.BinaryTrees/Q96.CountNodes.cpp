/*
Count number of Nodes in Binary Tree 
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
int countNodes(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    ans += countNodes(root->left);
    ans += countNodes(root->right);
    return ans;
}
int main()
{
    BinaryTree<int> *root = inputLineWise();
    cout << "Number of nodes in a binary tree: " << countNodes(root);
}