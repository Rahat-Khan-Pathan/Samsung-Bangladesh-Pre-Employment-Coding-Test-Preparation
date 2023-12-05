#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool vis[20];
int ans;
void back(int p1, int p2)
{
    if (p1 == p2)
    {
        if (p1 > ans)
            ans = p1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            back(p1 + a[i], p2);
            back(p1, p2 + a[i]);
            vis[i] = false;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(vis, false, sizeof(vis));
    ans = INT_MIN;
    back(0, 0);
    cout << ans << endl;
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