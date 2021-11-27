/*
Count the number of leaf in a generic Tree
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

int numberOfLeaf(Tree<int> *root)
{
    if (root->childrens.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        ans += numberOfLeaf(root->childrens[i]);
    }
    return ans;
}
int main()
{
    Tree<int> *root = input();
    cout << "Number of leaf in the given tree are : " << numberOfLeaf(root) << endl;
}