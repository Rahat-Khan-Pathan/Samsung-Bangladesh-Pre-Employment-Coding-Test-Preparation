#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
vector<vector<int>> v(20, vector<int>(20));
int n;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}
bool vis[20][20];
vector<pi> dis = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void bfs(int si, int sj, int l, int m, vector<vector<int>> &cp)
{
    queue<pair<pi, int>> q;
    q.push({{si, sj}, 0});
    while (!q.empty())
    {
        pair<pi, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int cl = p.second;
        if (cl > l)
            continue;
        if (vis[i][j])
            continue;
        vis[i][j] = true;
        if (cp[i][j] == m - 1)
        {
            cp[i][j] = m;
        }
        for (int d = 0; d < 4; d++)
        {
            int xi = i + dis[d].first;
            int xj = j + dis[d].second;
            if (valid(xi, xj) && !vis[xi][xj] && v[xi][xj] == 1)
            {
                q.push({{xi, xj}, cl + 1});
            }
        }
    }
}
int cs = 1;
void solve()
{
    int q;
    cin >> n >> q;
    vector<pi> vp(q);
    for (int i = 0; i < q; i++)
    {
        cin >> vp[i].first >> vp[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i <= 20; i++)
    {
        vector<vector<int>> cp(20, vector<int>(20, 0));
        for (int j = 0; j < q; j++)
        {
            memset(vis, false, sizeof(vis));
            bfs(vp[j].first - 1, vp[j].second - 1, i, j + 1, cp);
        }
        for (int d = 0; d < n; d++)
        {
            for (int e = 0; e < n; e++)
            {
                if (cp[d][e] == q)
                {
                    cout << "#" << cs++ << " " << i << endl;
                    return;
                }
            }
        }
    }
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