/*
Problem Statement: Pair sum to 0
Problem Level: MEDIUM
Problem Description:
Given a random integer array A of size N. count no of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
*/
#include "iostream"
#include "unordered_map"
using namespace std;
int main()
{
    int len;
    cout << "Enter the length of array: " << endl;
    cin >> len;
    int sum;
    int *arr = new int[len];
    cout << "Enter the sum you want to achieve: ";
    cin >> sum;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
    {
        map[arr[i]]++;
    }
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (map.count(sum - arr[i]))
        {
            counter += map[sum - arr[i]];
        }
        if (arr[i] == sum - arr[i])
            --counter;
    }
    cout << "Number of pairs: " << counter / 2 << endl;
}