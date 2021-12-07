#include "iostream"
#include "vector"
using namespace std;

class MaxPriorityQueue
{
private:
    vector<int> pq;
    void swap(int i, int j)
    {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

public:
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return getSize() == 0;
    }
    int getMax()
    {
        if (isEmpty())
        {
            cout << "Empty priority Queue." << endl;
            return -1;
        }
        return pq[0];
    }

    void insert(int val)
    {
        pq.push_back(val);
        int childIndex = getSize() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] <= pq[childIndex])
            {
                swap(childIndex, parentIndex);
                childIndex = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    int remove()
    {
        if (isEmpty())
        {
            cout << "Empty priority Queue." << endl;
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[getSize() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < getSize())
        {
            int c1 = 2 * parentIndex + 1;
            int c2 = 2 * parentIndex + 2;
            if (c1 < getSize() && pq[c1] >= pq[parentIndex] && pq[c1] >= pq[c2])
            {
                swap(c1, parentIndex);
                parentIndex = c1;
            }
            else if (c2 < getSize() && pq[c2] >= pq[parentIndex] && pq[c2] >= pq[c1])
            {
                swap(c2, parentIndex);
                parentIndex = c2;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    MaxPriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(50);
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(50);
    pq.insert(50);
    while (pq.getSize() != 0)
    {
        cout << pq.remove() << " ";
    }
}