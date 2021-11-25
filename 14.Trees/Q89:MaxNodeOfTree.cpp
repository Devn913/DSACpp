#include "iostream"
#include "vector"
#include "queue"
#include <bits/stdc++.h>
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
Tree<int> MaxNode(Tree<int> *root)
{
    Tree<int> max = *root;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        if (max.data < max.childrens[i]->data)
        {
            max = *max.childrens[i];
        }
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        if (MaxNode(max.childrens[i]).data > max.data)
        {
            max = MaxNode(max.childrens[i]);
        }
    }
    return max;
}
int main()
{
    Tree<int> *root = input();
    cout << "max " << MaxNode(root).data << endl;
}