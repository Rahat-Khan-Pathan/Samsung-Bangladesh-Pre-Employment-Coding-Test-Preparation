#include <bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
int ans[20][20];
bool valid(int i, int j)
{
    return ((a[i][j] == 0 || a[i][j] == 2) && (i >= 0 && i < n && j >= 0 && j < n));
}
vector<pair<int, int>> vp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int finalAns;
void dfs(int i, int j, int cnt)
{
    if (i == n - 1 && j == n - 1)
    {
        if (cnt <= finalAns)
            return;
        finalAns = cnt;
        for (int p = 0; p < n; p++)
        {
            for (int q = 0; q < n; q++)
            {
                ans[p][q] = a[p][q];
            }
        }
        return;
    }
    for (pair<int, int> p : vp)
    {
        int xi = i + p.first;
        int xj = j + p.second;
        if (valid(xi, xj))
        {
            int val = a[xi][xj];
            a[xi][xj] = 3;
            if (val == 2)
                dfs(xi, xj, cnt + 1);
            else
                dfs(xi, xj, cnt);
            a[xi][xj] = val;
        }
    }
}
int cs = 1;
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    finalAns = 0;
    a[0][0] = 3;
    dfs(0, 0, 0);
    cout << "Case #" << cs++ << endl;
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            cout << ans[p][q] << " ";
        }
        cout << endl;
    }
    cout << finalAns << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}