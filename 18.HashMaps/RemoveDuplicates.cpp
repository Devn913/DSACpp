/*
Given an array fo numbers you need to return a vector with no duplicates with preserving element order
*/
#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;

vector<int> *removeDuplicate(int *arr, int len)
{
    unordered_map<int, bool> map;
    vector<int> *res = new vector<int>();
    for (int i = 0; i < len; i++)
    {
        if (map.count(arr[i]) > 0)
        {
            continue;
        }
        else
        {
            res->push_back(arr[i]);
            map[arr[i]] = true;
        }
    }
    return res;
}

int main()
{
    int len;
    cout << "Enter len: ";
    cin >> len;
    int *arr = new int[len];
    int counter = 0;
    while (counter < len)
    {
        cin >> arr[counter];
        counter++;
    }

    vector<int> *res = removeDuplicate(arr, len);
    for (int i = 0; i < res->size(); i++)
    {
        cout << res->at(i) << " ";
    }
}