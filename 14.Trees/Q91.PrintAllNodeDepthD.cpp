/*
Print all Node of a Tree in the guven depth d
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

template <typename T>
class Tree
{
public:
    T data;
    vector<Tree<T> *> childrens;
    Tree(T val)
    {
        data = val;
    }
};

Tree<int> *input()
{
    int data;
    cout << "Enter the data for the root: ";
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    queue<Tree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children for " << front->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cout << "Enter the data for " << i << "th childer of " << front->data << " : ";
            cin >> data;
            Tree<int> *node = new Tree<int>(data);
            q.push(node);
            front->childrens.push_back(node);
        }
    }
    return root;
}

void printAtDepth(Tree<int> *root, int depth)
{
    if (depth < 0)
    {
        return;
    }
    if (depth == 0)
    {
        cout << root->data << " ";
    }
    depth--;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        printAtDepth(root->childrens[i], depth);
    }
}
int main()
{
    Tree<int> *root = input();
    printAtDepth(root, 1);
}