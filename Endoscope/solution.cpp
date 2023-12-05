#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
bool upor(int i)
{
    return (i == 1 || i == 2 || i == 4 || i == 7);
}
bool niche(int i)
{
    return (i == 1 || i == 2 || i == 5 || i == 6);
}
bool bame(int i)
{
    return (i == 1 || i == 3 || i == 6 || i == 7);
}
bool dane(int i)
{
    return (i == 1 || i == 3 || i == 4 || i == 5);
}
int a[100][100];
bool vis[100][100];
int n, m;
vector<pair<int, int>> vp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int bfs(int si, int sj, int l)
{
    if (a[si][sj] == 0)
        return 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, 1});
    vis[si][sj] = true;
    int ans = 0;
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int c = p.second;
        if (c > l)
            continue;
        ans++;
        // cout << i << " " << j << endl;
        for (int d = 0; d < 4; d++)
        {
            int xi = i + vp[d].first;
            int xj = j + vp[d].second;

            if (valid(xi, xj) && !vis[xi][xj] && a[xi][xj] != 0)
            {
                if (d == 0 && dane(a[i][j]) && bame(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 1 && bame(a[i][j]) && dane(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 2 && niche(a[i][j]) && upor(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 3 && upor(a[i][j]) && niche(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
            }
        }
    }
    return ans;
}
void solve()
{
    int si, sj, l;
    cin >> n >> m >> si >> sj >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            cin >> a[i][j];
        }
    }

    cout << bfs(si, sj, l) << endl;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
