/*
In the Genric tree, replace the node value to its depth 
*/
#include "iostream"
#include "queue"
#include "vector"
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
    cout << "Enter the data for root node: ";
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    queue<Tree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter the the number of child for " << front->data << " node: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cout << "Enter the data for " << i << "th noode of " << front->data << " : ";
            cin >> data;
            Tree<int> *node = new Tree<int>(data);
            q.push(node);
            front->childrens.push_back(node);
        }
    }
    return root;
}

void replaceDepth(Tree<int> *root, int depth = 0)
{
    root->data = depth;
    depth++;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        replaceDepth(root->childrens[i], depth);
    }
}
int main()
{
    Tree<int> *root = input();
    replaceDepth(root);
}
