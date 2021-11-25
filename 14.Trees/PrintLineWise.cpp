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
void print(Tree<int> *root)
{
    queue<Tree<int>> q;
    q.push(*root);
    while (!q.empty())
    {
        Tree<int> front = q.front();
        cout << front.data << ": ";
        for (int i = 0; i < front.childrens.size(); i++)
        {
            cout << front.childrens[i]->data << " ,";
            q.push(*front.childrens[i]);
        }
        q.pop();
        cout << endl;
    }
}
int main()
{
    Tree<int> *root = inputLineWise();
    print(root);
}