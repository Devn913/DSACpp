/*
Problem Statement: Maximum Frequency Number
Problem Level: EASY
Problem Description:
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
*/
#include "iostream"
#include "unordered_map"
using namespace std;
int main()
{
    int len;
    cout << "Enter the length of array: " << endl;
    cin >> len;
    int *arr = new int[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
    {
        map[arr[i]]++;
    }
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (map[arr[i]] > max)
        {
            max = arr[i];
        }
    }
    cout << max;
}