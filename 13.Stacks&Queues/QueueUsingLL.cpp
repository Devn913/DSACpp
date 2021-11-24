/*
 * Queue Implementation using Linked List
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int value){
        next = NULL;
        val = value;
    }
};
class Queue{
    Node *head;
    Node *tail;
    int size;
public:
    Queue(){
        head = tail =NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(int val){
        Node *temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    int peek(){
        if(size == 0){
            cout <<"Queue is empty. "<< endl;
            return -1;
        }
        return head->val;
    }
    int dequeue(){
        if(size == 0){
            cout <<"Queue is empty. "<< endl;
            return -1;
        }
        int val = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return val;
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.getSize() << endl;
    cout << q.dequeue()<<" ";
    cout << q.dequeue()<<" ";
    cout << q.dequeue()<<" ";
    cout << q.dequeue()<<" ";
    cout << q.dequeue()<<" ";
    cout << q.getSize();
    q.enqueue(100);
    q.enqueue(120);
    q.enqueue(2300);
    q.enqueue(200);
    cout << q.getSize() << endl;
    while(!(q.isEmpty())){
        cout << q.dequeue() << " ";
    }
}