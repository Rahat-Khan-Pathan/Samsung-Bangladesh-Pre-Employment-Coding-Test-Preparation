#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[20][20];
bool vis[20][20];
vector<pair<int, int>> vp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int bfs(int si, int sj)
{
    int ans = -1;
    if (a[si][sj] == 0)
        return 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, 1});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;

        int c = p.second;
        if (a[i][j] == 1)
            ans = max(ans, c);
        // cout << i << " " << j << " " << c << endl;
        for (int d = 0; d < 4; d++)
        {
            int xi = i + vp[d].first;
            int xj = j + vp[d].second;
            if (valid(xi, xj) && !vis[xi][xj] && a[xi][xj] == 1)
            {
                vis[xi][xj] = true;
                q.push({{xi, xj}, c + 1});
            }
        }
    }
    return ans;
}
void solve()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            cin >> a[i][j];
        }
    }
    int sx, sy;
    cin >> sx >> sy;
    swap(sx, sy);
    a[sx][sy] = 1;
    sx--;
    sy--;
    cout << bfs(sx, sy) << endl;
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