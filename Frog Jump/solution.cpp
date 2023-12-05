#include <bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
int ans;
bool vis[20][20];
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}
void bfs(int i, int j, int di, int dj)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    vis[i][j] = true;
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int si = p.first.first;
        int sj = p.first.second;
        int c = p.second;
        // cout << si << " " << sj << " " << c << endl;
        if (si == di && sj == dj)
        {
            cout << c << endl;
            return;
        }
        if (a[si][sj] == 1)
        {
            if (valid(si, sj + 1) && !vis[si][sj + 1] && a[si][sj + 1] == 1)
            {
                q.push({{si, sj + 1}, c});
                vis[si][sj + 1] = true;
            }
            if (valid(si, sj - 1) && !vis[si][sj - 1] && a[si][sj - 1] == 1)
            {
                q.push({{si, sj - 1}, c});
                vis[si][sj - 1] = true;
            }
            if (valid(si - 1, sj) && !vis[si - 1][sj])
            {
                q.push({{si - 1, sj}, c + 1});
                vis[si - 1][sj] = true;
            }
            if (valid(si + 1, sj) && !vis[si + 1][sj])
            {
                q.push({{si + 1, sj}, c + 1});
                vis[si + 1][sj] = true;
            }
        }
        else
        {
            if (valid(si - 1, sj) && !vis[si - 1][sj])
            {
                q.push({{si - 1, sj}, c});
                vis[si - 1][sj] = true;
            }
            if (valid(si + 1, sj) && !vis[si + 1][sj])
            {
                q.push({{si + 1, sj}, c});
                vis[si + 1][sj] = true;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    ans = INT_MAX;
    memset(vis, false, sizeof(vis));
    bfs(si, sj, di, dj);
    return 0;
}
