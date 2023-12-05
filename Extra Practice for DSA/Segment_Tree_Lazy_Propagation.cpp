// This is not for pre-employment test
// Question Link - https://lightoj.com/problem/binary-simulation

#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
struct
{
    int pre;
    char c;
} tree[3 * mx];
void build(int node, int l, int r, string &a)
{
    if (l == r)
    {
        tree[node].c = a[l];
        tree[node].pre = 0;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (l + r) / 2;
    build(left, l, mid, a);
    build(right, mid + 1, r, a);
    tree[node].pre = 0;
}
int query(int node, int l, int r, int i, int carry, string &s)
{
    if (l == r)
    {
        if (l == i)
            return (s[i] - '0' + carry + tree[node].pre) % 2;
        else
            return 0;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (l + r) / 2;
    if (l <= i && i <= mid)
        return query(left, l, mid, i, carry + tree[node].pre, s);
    return query(right, mid + 1, r, i, carry + tree[node].pre, s);
}
void update(int node, int l, int r, int i, int j)
{
    if (l >= i && r <= j)
    {
        tree[node].pre++;
        return;
    }
    if (r < i || l > j)
    {
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, i, j);
    update(right, mid + 1, r, i, j);
}
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        cout << "Case " << cs++ << ":" << endl;
        string s;
        cin >> s;
        int n = s.size();
        build(1, 0, n - 1, s);
        int q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'I')
            {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                update(1, 0, n - 1, a, b);
            }
            else
            {
                int x;
                cin >> x;
                x--;
                cout << query(1, 0, n - 1, x, 0, s) << endl;
            }
        }
    }
    return 0;
}