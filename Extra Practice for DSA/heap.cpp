// This is not for pre-employment test

#include <bits/stdc++.h>
using namespace std;
class maxHeap
{
public:
    vector<int> v;
    int sz;
    maxHeap()
    {
        v.push_back(-1);
        sz = 0;
    }
    void insert(int val)
    {
        v.push_back(val);
        sz++;
        int curSize = sz;
        while (curSize > 1)
        {
            int par = curSize / 2;
            if (v[par] < v[curSize])
            {
                swap(v[par], v[curSize]);
                curSize = par;
            }
            else
                break;
        }
    }
    int size()
    {
        return sz;
    }
    int top()
    {
        return v[1];
    }
    void heapify(int idx)
    {
        int left = idx * 2;
        int right = left + 1;
        if (left > sz)
            return;
        if (right > sz)
        {
            if (v[left] >= v[idx])
            {
                swap(v[left], v[idx]);
                heapify(left);
            }
            else
            {
                return;
            }
        }
        if (v[left] >= v[idx] && v[left] >= v[right])
        {
            swap(v[left], v[idx]);
            heapify(left);
        }
        else if (v[right] >= v[idx] && v[right] >= v[left])
        {
            swap(v[right], v[idx]);
            heapify(right);
        }
        else
            return;
    }
    void remove()
    {
        v[1] = v.back();
        v.pop_back();
        sz--;
        heapify(1);
    }
};
int main()
{
    maxHeap pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(100);
    pq.insert(50);
    pq.insert(30);
    for (int i = 1; i < pq.v.size(); i++)
        cout << pq.v[i] << " ";
    cout << endl;
    pq.remove();
    cout << pq.top() << endl;
    for (int i = 1; i < pq.v.size(); i++)
        cout << pq.v[i] << " ";
    cout << endl;
    return 0;
}