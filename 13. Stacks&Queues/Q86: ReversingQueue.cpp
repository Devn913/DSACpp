/*
Problem Statement: Reverse Queue
Problem Level: EASY
Problem Description:
You have been given a queue that can store integers as the data.
You are required to write a function that reverses the populated queue itself without using any other data structures.
*/
#include "iostream"
#include "queue"
using namespace std;
queue<int> reverse(queue<int> q){
    if(q.size()==0 || q.size()==1) return q;
    int val = q.front();
    q.pop();
    q = reverse(q);
    q.push(val);
    return q;
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q = reverse(q);
    while(!(q.empty())){
        cout << q.front() << " ";
        q.pop();
    }

}