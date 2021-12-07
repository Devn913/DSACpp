#include "iostream"
#include "vector"
using namespace std;
class PriorityQueue
{
private:
    vector<int> pq;

public:
    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return getSize() == 0;
    }

    int getMin()
    {
        if (isEmpty())
        {
            cout << "Prority Queue is empty" << endl;
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
            if (pq[parentIndex] >= pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
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
            cout << "Empty priority queue." << endl;
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
            if (c1 < getSize() && pq[c1] <= pq[parentIndex] && pq[c1] <= pq[c2])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[c1];
                pq[c1] = temp;
                parentIndex = c1;
            }
            else if (c2 < getSize() && pq[c2] <= pq[parentIndex] && pq[c2] <= pq[c1])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[c2];
                pq[c2] = temp;
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
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(50);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);
    pq.insert(40);
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);
    while (pq.getSize() != 0)
    {
        cout << pq.remove() << " ";
    }
}
