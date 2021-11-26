/*
Code : Find height
Given a generic tree, find and return the height of given tree.
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
    vector<Tree<int> *> childrens;
    Tree(T val)
    {
        data = val;
    }
};
Tree<int> *input()
{
    int data;
    cout << "Enter the value for root node: ";
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    queue<Tree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter the number of nodes you want in " << front->data << " :";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cout << "Enter the data for " << i << "th node in " << front->data << " Node: ";
            cin >> data;
            Tree<int> *node = new Tree<int>(data);
            q.push(node);
            front->childrens.push_back(node);
        }
    }
    return root;
}
int height(Tree<int> *root)
{
    if (root->childrens.size() == 0)
    {
        return 1;
    }
    int max = 0;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        int res = height(root->childrens[i]);
        if (res > max)
        {
            max = res;
        }
    }
    return max + 1;
}
int main()
{
    Tree<int> *root = input();
    cout << "Heigh: " << height(root);
}