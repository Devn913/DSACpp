/*
Node having Sum of children and node max
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
int maxNodeChildSum(Tree<int> *root)
{
    int maxSum = root->data;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        maxSum += root->childrens[i]->data;
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        int temp = maxNodeChildSum(root->childrens[i]);
        if (temp > maxSum)
        {
            maxSum = temp;
        }
    }
    return maxSum;
}
int main()
{
    Tree<int> *root = input();
    cout << maxNodeChildSum(root) << endl;
}