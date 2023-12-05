#include <bits/stdc++.h>
#define pi pair<int, double>
using namespace std;
void dfs(int s, int n, int t, double p, vector<pi> v[], vector<double> &ans)
{
    if (t <= 0)
    {
        ans[s] += p;
        return;
    }
    for (pi c : v[s])
    {
        if (c.second != 0.0)
        {
            p *= c.second;
            dfs(c.first, n, t - 10, p, v, ans);
            p /= c.second;
        }
    }
}
void solve()
{
    int n, e, t;
    cin >> n >> e >> t;
    vector<pi> v[20];
    vector<double> ans(20, 0.0);
    while (e--)
    {
        int a, b;
        double c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    dfs(1, n, t, 1.0, v, ans);
    int node;
    double ss = 0.0;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] > ss)
        {
            ss = ans[i];
            node = i;
        }
    }
    cout << node << " ";
    cout << fixed << setprecision(6) << ans[node] << endl;
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