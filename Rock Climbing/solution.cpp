#include <bits/stdc++.h>
using namespace std;
int a[15][15];
bool vis[15][15];
int n, m;
bool ans;
void dfs(int i, int j, int l)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if (vis[i][j])
        return;
    vis[i][j] = true;
    if (a[i][j] == 3)
    {
        ans = true;
        return;
    }
    if (j + 1 < m && a[i][j + 1] != 0 && !vis[i][j + 1])
        dfs(i, j + 1, l);
    if (j - 1 >= 0 && a[i][j - 1] != 0 && !vis[i][j - 1])
        dfs(i, j - 1, l);
    for (int h = 1; h <= l; h++)
    {
        if (i - h >= 0 && a[i - h][j] != 0 && !vis[i - h][j])
            dfs(i - h, j, l);
        if (i + h < n && a[i + h][j] != 0 && !vis[i + h][j])
            dfs(i + h, j, l);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int l = 0; l <= n; l++)
    {
        ans = false;
        memset(vis, false, sizeof(vis));
        dfs(n - 1, 0, l);
        if (ans)
        {
            cout << l << endl;
            break;
        }
    }
    return 0;
}