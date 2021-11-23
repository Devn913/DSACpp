#include "iostream"
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;
    int front;
    int current;
    int size;
    int capacity;

public:
    Queue(int cap)
    {
        arr = new T[cap];
        capacity = cap;
        front = -1;
        size = 0;
        current = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T val)
    {
        if (size == capacity)
        {
            cout << "Queue is full." << endl;
            return;
        }
        arr[current] = val;
        current = (current + 1) % capacity;
        size++;
        if (front == -1)
        {
            front = 0;
        }
    }

    T peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return arr[front];
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T val = arr[front];
        size--;
        front = (front + 1) % capacity;
        if (size == 0)
        {
            front = -1;
            current = 0;
        }
        return val;
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(60);
    q.enqueue(50);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}