// This is not for pre-employment test
// Question Link - https://codeforces.com/problemset/problem/25/D
#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int mx = 1e5 + 5;
int par[mx];
int parentRank[mx];
void dsu_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        parentRank[i] = 0;
    }
}
int dsu_find(int v)
{
    if (par[v] == -1)
        return v;
    return par[v] = dsu_find(par[v]);
}
void dsu_union(int a, int b)
{
    int parA = dsu_find(a);
    int parB = dsu_find(b);
    if (parA != parB)
    {
        if (parentRank[parA] < parentRank[parB])
            swap(parA, parB);
        par[parB] = parA;
        if (parentRank[parA] == parentRank[parB])
            parentRank[parB]++;
    }
}
int main()
{
    int n;
    cin >> n;
    dsu_set(n);
    int e = n - 1;
    vector<pi> bad;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if (leaderU == leaderV)
        {
            bad.push_back({u, v});
        }
        else
        {
            dsu_union(u, v);
        }
    }
    vector<pi> add;
    for (int i = 2; i <= n; i++)
    {
        if (dsu_find(1) != dsu_find(i))
        {
            add.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout << bad.size() << endl;
    for (int i = 0; i < bad.size(); i++)
    {
        cout << bad[i].first << " " << bad[i].second << " " << add[i].first << " " << add[i].second << endl;
    }
    return 0;
}