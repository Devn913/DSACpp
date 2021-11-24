/*
 * Implementation of Queue using Arrays
 */
#include "iostream"
using namespace std;
class Queue{
    int *arr;
    int size;
    int capacity;
    int frontIndex;
    int nextIndex;
public:
    Queue(int cap){
        arr = new int[cap];
        size = 0;
        capacity = cap;
        frontIndex = -1;
        nextIndex = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int val){
        if(size == capacity){
            cout << "Queue is full. " << endl;
            return;
        }
        arr[nextIndex] = val;
        nextIndex = (nextIndex +1) %capacity;
        size++;
        if(frontIndex==-1) frontIndex = 0;
    }

    int peek(){
        if(size==0){
            cout << "Queue is Empty. "<<endl;
            return -1;
        }
        return arr[frontIndex];
    }

    int dequeue(){
        if(size==0){
            cout << "Queue is Empty. "<<endl;
            return -1;
        }
        int val = arr[frontIndex];
        frontIndex = (frontIndex+1)%capacity;
        size--;
        if(size == 0){
            frontIndex = -1;
            nextIndex = 0;
        }
        return val;
    }
};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout <<"size: " << q.getSize() << "Peek: " << q.peek() << endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    q.enqueue(60);
    cout <<"size: " << q.getSize() << "Peek: " << q.peek() << endl;
    q.enqueue(70);
    cout << "dequeu: "<<q.dequeue() <<endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    cout << "dequeu: "<<q.dequeue() <<endl;
    q.enqueue(700);
    q.enqueue(700);
    q.enqueue(700);
    cout <<"size: " << q.getSize() << "Peek: " << q.peek() << endl;
    cout << "dequeu: "<<q.dequeue() <<endl;

}