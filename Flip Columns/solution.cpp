#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
int n, m;
void flip(int col, vector<vector<int>> &v)
{
    for (int i = 0; i < n; i++)
    {
        v[i][col] = !v[i][col];
    }
}
int finalAns;
void back(int col, int k, vector<vector<int>> v)
{
    if (k == 0)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 1)
                    cnt++;
            }
            if (cnt == m)
                ans++;
        }
        finalAns = max(finalAns, ans);
        return;
    }
    if (col >= m)
        return;
    // won't flip current column
    back(col + 1, k, v);
    // flip current column p number of times and check for others
    vector<vector<int>> cpy = v;
    for (int p = 1; p <= k; p++)
    {
        flip(col, cpy);
        back(col + 1, k - p, cpy);
    }
}
void solve()
{
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> v(20, vector<int>(20));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    finalAns = 0;
    back(0, k, v);
    cout << finalAns << endl;
}
int main()
{
    fast;
    solve();
    return 0;
}
