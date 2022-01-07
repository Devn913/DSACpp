/*
In order Traversal using stack
*/
#include "iostream"
#include "stack"
#include "queue"
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree(T val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
BinaryTree<int> *inputLineWise()
{
    cout << "Enter root data: ";
    int data;
    cin >> data;
    BinaryTree<int> *root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *front = q.front();
        q.pop();
        int val;
        cout << "Enter left val for " << front->data << " -1 for NULL: ";
        cin >> val;
        if (val != -1)
        {
            front->left = new BinaryTree<int>(val);
            q.push(front->left);
        }
        cout << "Enter right val for " << front->data << " -1 for NULL: ";
        cin >> val;
        if (val != -1)
        {
            front->right = new BinaryTree<int>(val);
            q.push(front->right);
        }
    }
    return root;
}
void inOrder(BinaryTree<int> *root){
    stack<BinaryTree<int> *> s;
    BinaryTree<int> *current = root;
    while (current != NULL || !s.empty() )
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;

        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }   
    
}
int main(){
    BinaryTree<int> *root = inputLineWise();
    inOrder(root);
}