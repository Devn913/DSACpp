/*
Next larger Element in a tree
*/
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

int nextLarger(Tree<int> *root, int val)
{
    int ans = INT_MAX;
    if (root->data > val)
    {
        ans = root->data;
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        int temp = nextLarger(root->childrens[i], val);
        if (temp < ans)
        {
            ans = temp;
        }
    }
    return ans;
}
int main()
{
    Tree<int> *root = input();
    int ans = nextLarger(root, 10);
    if (ans != INT_MAX)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "doesn't exist " << endl;
    }
}