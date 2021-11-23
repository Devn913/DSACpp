#include "iostream"
using namespace std;

template <typename T>
class Node{
public:
  T val;
  Node<T> *next;
  Node(T value){
      val = value;
      next = NULL;
  }
};

template <typename T>
class Stack{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;
public:

  Stack(){
    size = 0;
    head = tail = NULL;
  }

  bool isEmpty(){
    return size==0;
  }

  int getSize(){
    return size;
  }

  void push(T val){
    Node<T> *temp = new Node<T>(val);
    if(size==0){
      head = tail = temp;
    }else{
      temp->next = head;
      head = temp;
    }
    size++;
  }

  T peek(){
    if(size==0){
      cout << "Stack is Empty. " << endl;
      return 0;
    }
    return head->val;
  }

  T pop(){
    if(size==0){
      cout << "Stack is Empty. " << endl;
      return 0;
    }
    T val = head->val;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
    return val;
  }

};

int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.getSize() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;

}