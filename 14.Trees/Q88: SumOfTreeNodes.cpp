/*
Code : Find sum of nodes
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form.
The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.   
Output Format :
The first and only line of output prints the sum of all nodes of the given generic tree. 
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
    cout << "Enter the value of Root: " << endl;
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
            cout << "Enter the " << i << "th node value for" << front->data << " node :";
            int data;
            cin >> data;
            Tree<int> *node = new Tree<int>(data);
            q.push(node);
            front->childrens.push_back(node);
        }
    }
    return root;
}
int sumOfTreeNodes(Tree<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        ans += sumOfTreeNodes(root->childrens[i]);
    }
    return ans;
}
int main()
{
    Tree<int> *root = input();
    cout << "Sum of Node is : " << sumOfTreeNodes(root) << endl;
}