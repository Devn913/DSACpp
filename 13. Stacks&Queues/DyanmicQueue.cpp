/*
 * Dynamic Queue implementation using Dynamic array
 */
#include "iostream"
using namespace std;
class Queue{
    int *arr;
    int frontIndex;
    int size;
    int capacity;
    int nextIndex;
public:
    Queue(){
        capacity = 5;
        arr = new int[capacity];
        frontIndex = -1;
        size =0;
        nextIndex = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int val){
        if(size==capacity){
            int *newArr = new int[capacity*2];
            int counter = 0;
            while (!(isEmpty())){
                newArr[counter] = dequeue();
                counter++;
            }
            frontIndex = 0;
            size = capacity;
            nextIndex = capacity;
            delete [] arr;
            arr = newArr;
            capacity = capacity*2;
        }
        arr[nextIndex] = val;
        nextIndex = (nextIndex+1)%capacity;
        size++;
        if(frontIndex==-1){
            frontIndex = 0;
        }
    }

    int peek(){
        if(size == 0){
            cout << "Stack is empty. " << endl;
            return -1;
        }
        return arr[frontIndex];
    }
    int dequeue(){
        if(size == 0){
            cout << "Stack is empty. " << endl;
            return -1;
        }
        int val = arr[frontIndex];
        frontIndex= (frontIndex+1)%capacity;
        size--;
        if(size ==0){
            frontIndex = -1;
            nextIndex = 0;
        }
        return val;
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.peek() << endl;
    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(100);
    q.enqueue(1200);
    q.enqueue(1300);
    q.enqueue(13300);
    q.enqueue(1200);
    q.enqueue(13200);
    q.enqueue(1020);
    cout << q.getSize() << endl;
    cout << q.peek() << endl;




}