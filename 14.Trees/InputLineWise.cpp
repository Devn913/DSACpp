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

Tree<int> *inputLineWise()
{
    int data;
    cout << "Enter the data in the node: ";
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    queue<Tree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter the number of childern: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cout << "Enter the data: ";
            cin >> data;
            Tree<int> *node = new Tree<int>(data);
            q.push(node);
            front->childrens.push_back(node);
        }
    }
    return root;
}
void printTree(Tree<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->childrens.size(); i++)
    {
        cout << root->childrens[i]->data << " , ";
    }
    cout << endl;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        printTree(root->childrens[i]);
    }
}

int main()
{
    Tree<int> *root = inputLineWise();
    printTree(root);
}