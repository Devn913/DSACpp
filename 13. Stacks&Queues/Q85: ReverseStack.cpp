/*
Problem Statement: Reverse a Stack
Problem Level: MEDIUM
Problem Description:
You have been given two stacks that can store integers as the data.
Out of the two given stacks, one is populated and the other one is empty.
You are required to write a function that reverses the populated stack using the one which is empty.
 */
#include "iostream"
#include "stack"
using namespace std;
stack<int> reverse(stack<int> s1, stack<int> s2){
    if(s1.size() == 1 || s1.size() == 0) return s1;
    int val = s1.top();
    s1.pop();
    s1 = reverse(s1,s2);
    while (!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(val);
    while(!(s2.empty())){
        s1.push(s2.top());
        s2.pop();
    }
    return s1;

}
int main(){
    stack<int> s1;
    stack<int> s2;
    s1.push(10);
    s1.push(102);
    s1.push(120);
    s1.push(1320);
    s1 = reverse(s1,s2);
    while (!(s1.empty())){
        cout << s1.top() << " ";
        s1.pop();
    }
}