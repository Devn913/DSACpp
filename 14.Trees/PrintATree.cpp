#include "iostream"
#include "vector"
using namespace std;

template <typename T>
class Tree
{
public:
    T data;
    vector<Tree<T> *> children;
    Tree(T val)
    {
        data = val;
    }
};

Tree<int> *input()
{
    int data;
    cout << "Enter the val: " << endl;
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    int n;
    cout << "Enter the number of childrens: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Tree<int> *child = input();
        root->children.push_back(child);
    }
    return root;
}

void printTree(Tree<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    Tree<int> *root = input();
    printTree(root);
}