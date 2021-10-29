/*
Problem Statement: Check redundant brackets
Problem Level: MEDIUM
Problem Description:
For a given expression in the form of a string, find if there exist any redundant brackets or not.
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
*/
#include "iostream"
#include "stack"
using namespace std;
bool check(string input){
    int len = input.size();
    stack<char> s;
    for(int i =0;i<len;i++){
        int count = 0;
        while (input[i] != ')'){
            s.push(input[i]);
            i++;
        }
        while (s.top() != '('){
            s.pop();
            count++;
        }
        s.pop();
        if(count==0){
            return true;
        }
    }
    return false;
}
int main(){
    string s = "(a+b)+((c))";
    if(check(s)){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << endl;
}